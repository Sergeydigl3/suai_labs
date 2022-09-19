// #include <cstring>
#include <cstdlib>
#include <stdint.h>

using namespace std;

typedef struct {
	uint8_t* BytePointer;
	uint32_t BitPosition;
} BitStream;

typedef struct {
	uint32_t Symbol;
	uint32_t Count;
	uint32_t Code;
	uint32_t MyCode;
	uint32_t Bits;
} Symbol;

static void initBitStream(BitStream* stream, uint8_t* buffer)
{
	stream->BytePointer = buffer;
	stream->BitPosition = 0;
}

// split_2_groups(Symbol* sym)

static void writeBits(BitStream* stream, uint32_t x, uint32_t bits)
{
	uint8_t* buffer = stream->BytePointer;
	uint32_t bit = stream->BitPosition;
	uint32_t mask = 1 << (bits - 1);

	for (uint32_t count = 0; count < bits; ++count)
	{
		*buffer = (*buffer & (0xff ^ (1 << (7 - bit)))) + ((x & mask ? 1 : 0) << (7 - bit));
		x <<= 1;
		bit = (bit + 1) & 7;

		if (!bit)
		{
			++buffer;
		}
	}

	stream->BytePointer = buffer;
	stream->BitPosition = bit;
}

static void histogram(uint8_t* input, Symbol* sym, uint32_t size)
{
	Symbol temp;
	int i, swaps;

	for (i = 0; i < 256; ++i)
	{
		sym[i].Symbol = i;
		sym[i].Count = 0;
		sym[i].Code = 0;
		sym[i].Bits = 0;
	}

	for (i = size; i; --i)
	{
		sym[*input++].Count++;
	}

	do
	{
		swaps = 0;

		for (i = 0; i < 255; ++i)
		{
			if (sym[i].Count < sym[i + 1].Count)
			{
				temp = sym[i];
				sym[i] = sym[i + 1];
				sym[i + 1] = temp;
				swaps = 1;
			}
		}
	} while (swaps);
}

static void  makeTree(Symbol* sym, BitStream* stream, uint32_t code, uint32_t bits, uint32_t first, uint32_t last)
{
	uint32_t i, size, sizeA, sizeB, lastA, firstB;

	if (first == last)
	{
		writeBits(stream, 1, 1);
		writeBits(stream, sym[first].Symbol, 8);
		sym[first].Code = code;
		sym[first].Bits = bits;
		return;
	}
	else
	{
		writeBits(stream, 0, 1);
	}

	size = 0;

	for (i = first; i <= last; ++i)
	{
		size += sym[i].Count;
	}

	sizeA = 0;

	for (i = first; sizeA < ((size + 1) >> 1) && i < last; ++i)
	{
		sizeA += sym[i].Count;
	}

	if (sizeA > 0)
	{
		writeBits(stream, 1, 1);

		lastA = i - 1;

		makeTree(sym, stream, (code << 1) + 0, bits + 1, first, lastA);
	}
	else
	{
		writeBits(stream, 0, 1);
	}

	sizeB = size - sizeA;

	if (sizeB > 0)
	{
		writeBits(stream, 1, 1);

		firstB = i;

		makeTree(sym, stream, (code << 1) + 1, bits + 1, firstB, last);
	}
	else
	{
		writeBits(stream, 0, 1);
	}
}


static int Compress(uint8_t* input, uint8_t* output, uint32_t inputSize)
{
	Symbol sym[256], temp;
	BitStream stream;
	uint32_t i, totalBytes, swaps, symbol, lastSymbol;

	if (inputSize < 1)
		return 0;

	initBitStream(&stream, output);

	// считаем байты
	histogram(input, sym, inputSize);

	// crate new vector and callculate frequency of each symbol and write result 
	

	for (lastSymbol = 255; sym[lastSymbol].Count == 0; --lastSymbol);

	if (lastSymbol == 0)
		++lastSymbol;

	makeTree(sym, &stream, 0, 0, 0, lastSymbol);

	
	do
	{
		swaps = 0;

		for (i = 0; i < 255; ++i)
		{
			if (sym[i].Symbol > sym[i + 1].Symbol)
			{
				temp = sym[i];
				sym[i] = sym[i + 1];
				sym[i + 1] = temp;
				swaps = 1;
			}
		}
	} while (swaps);

	for (i = 0; i < inputSize; ++i)
	{
		symbol = input[i];
		writeBits(&stream, sym[symbol].Code, sym[symbol].Bits);
	}

	totalBytes = (int)(stream.BytePointer - output) + (stream.BitPosition > 0);

	return totalBytes;
}