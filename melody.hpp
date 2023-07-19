#pragma once

constexpr double BEAT_UNIT = 32 * 128.0 / 60000.0;

/* parse notes with js
arr = [...];
str = [0].concat(arr.map((e,i,a) => a.slice(0,i+1).reduce((a,b,c) => a +
b))).join(", "); copy(str);
*/

constexpr int LEN1 = 62;
constexpr int restField1[LEN1] = {
    0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
constexpr int notes1[LEN1] = {
    0, -5, 5, 3, -4, -2, 0, -2, 0, 8, 7, 5,  3, -2, 0,  2,  3,  7,  8,  7, 0,
    0, 3,  5, 7, 10, 8,  7, 5,  7, 4, 8, 7,  5, 8,  12, 14, 12, 10, 8,  7, 5,
    3, -2, 0, 2, 3,  7,  8, 7,  0, 0, 3, -1, 3, 2,  10, 5,  8,  7,  -2, 3};
constexpr int rhythm1[LEN1] = {
    16, 64, 16, 48,  16, 16,  16, 64, 48, 16, 16, 16, 32, 32, 32, 32,
    48, 80, 16, 16,  64, 112, 32, 16, 48, 32, 32, 32, 32, 48, 32, 16,
    16, 32, 16, 16,  32, 16,  64, 16, 16, 16, 32, 32, 32, 32, 48, 80,
    16, 16, 64, 112, 32, 16,  48, 32, 32, 32, 32, 32, 16, 64};
constexpr int timing1[LEN1 + 1] = {
    0,    16,   80,   96,   144,  160,  176,  192,  256,  304,  320,
    336,  352,  384,  416,  448,  480,  528,  608,  624,  640,  704,
    816,  848,  864,  912,  944,  976,  1008, 1040, 1088, 1120, 1136,
    1152, 1184, 1200, 1216, 1248, 1264, 1328, 1344, 1360, 1376, 1408,
    1440, 1472, 1504, 1552, 1632, 1648, 1664, 1728, 1840, 1872, 1888,
    1936, 1968, 2000, 2032, 2064, 2096, 2112, 2176};
constexpr int LEN2 = 330;
constexpr int notes2[LEN2] = {
    7,  -17, -5, 2,   -2, 7,  -2, 2,   -2, -17, -5, 2,   -2, 7,  -2, 2,   -2,
    10, 22,  21, 22,  19, 22, 17, 22,  15, 22,  14, 22,  12, 22, 10, 22,  9,
    21, 19,  21, 17,  21, 15, 21, 14,  21, 12,  21, 10,  21, 9,  21, 7,   19,
    17, 19,  15, 19,  14, 19, 12, 19,  10, 19,  9,  19,  7,  19, 19, -10, 18,
    16, 18,  -6, -3,  19, 19, -5, 2,   -2, 7,   -2, 2,   -2, 22, 10, 12,  10,
    14, 10,  15, 10,  17, 10, 19, 10,  21, 10,  22, 10,  21, 9,  10, 9,   12,
    9,  14,  9,  15,  9,  17, 9,  19,  9,  21,  9,  19,  7,  9,  7,  10,  7,
    12, 7,   14, 7,   15, 7,  17, 7,   19, 7,   19, -10, 18, 16, 18, -6,  -3,
    19, 19,  -5, 2,   -2, 7,  -2, 2,   -2, 22,  34, 33,  34, 31, 34, 29,  34,
    27, 34,  26, 34,  24, 34, 22, 34,  21, 33,  31, 33,  29, 33, 27, 33,  26,
    33, 24,  33, 22,  33, 21, 33, 19,  31, 29,  31, 27,  31, 26, 31, 24,  31,
    22, 31,  21, 31,  19, 31, 31, -10, 30, 28,  30, -6,  -3, 31, 31, -5,  2,
    -2, 7,   -2, 2,   -2, 34, 22, 24,  22, 26,  22, 27,  22, 29, 22, 31,  22,
    33, 22,  34, 22,  33, 21, 22, 21,  24, 21,  26, 21,  27, 21, 29, 21,  31,
    21, 33,  21, 31,  19, 21, 19, 22,  19, 24,  19, 26,  19, 27, 19, 29,  19,
    31, 19,  31, -10, 30, 28, 30, -6,  -3, 31,  31, -5,  2,  -2, 7,  -2,  2,
    -2, 10,  10, 22,  10, 21, 10, 19,  10, 17,  10, 15,  10, 14, 10, 12,  10,
    9,  9,   21, 9,   19, 9,  17, 9,   15, 9,   14, 9,   12, 9,  10, 9,   7,
    7,  19,  7,  17,  7,  15, 7,  14,  7,  12,  7,  10,  7,  9,  7,  7,   -10,
    6,  4,   6,  -6,  -3, 7,  7};
constexpr int timing2[LEN2 + 1] = {
    0,    32,   48,   64,   80,   96,   112,  128,  144,  160,  176,  192,
    208,  224,  240,  256,  272,  288,  304,  320,  336,  352,  368,  384,
    400,  416,  432,  448,  464,  480,  496,  512,  528,  544,  560,  576,
    592,  608,  624,  640,  656,  672,  688,  704,  720,  736,  752,  768,
    784,  800,  816,  832,  848,  864,  880,  896,  912,  928,  944,  960,
    976,  992,  1008, 1024, 1040, 1056, 1072, 1088, 1104, 1120, 1136, 1152,
    1168, 1184, 1200, 1216, 1232, 1248, 1264, 1280, 1296, 1312, 1328, 1344,
    1360, 1376, 1392, 1408, 1424, 1440, 1456, 1472, 1488, 1504, 1520, 1536,
    1552, 1568, 1584, 1600, 1616, 1632, 1648, 1664, 1680, 1696, 1712, 1728,
    1744, 1760, 1776, 1792, 1808, 1824, 1840, 1856, 1872, 1888, 1904, 1920,
    1936, 1952, 1968, 1984, 2000, 2016, 2032, 2048, 2064, 2080, 2096, 2112,
    2128, 2144, 2160, 2176, 2192, 2208, 2224, 2240, 2256, 2272, 2288, 2304,
    2320, 2336, 2352, 2368, 2384, 2400, 2416, 2432, 2448, 2464, 2480, 2496,
    2512, 2528, 2544, 2560, 2576, 2592, 2608, 2624, 2640, 2656, 2672, 2688,
    2704, 2720, 2736, 2752, 2768, 2784, 2800, 2816, 2832, 2848, 2864, 2880,
    2896, 2912, 2928, 2944, 2960, 2976, 2992, 3008, 3024, 3040, 3056, 3072,
    3088, 3104, 3120, 3136, 3152, 3168, 3184, 3200, 3216, 3232, 3248, 3264,
    3280, 3296, 3312, 3328, 3344, 3360, 3376, 3392, 3408, 3424, 3440, 3456,
    3472, 3488, 3504, 3520, 3536, 3552, 3568, 3584, 3600, 3616, 3632, 3648,
    3664, 3680, 3696, 3712, 3728, 3744, 3760, 3776, 3792, 3808, 3824, 3840,
    3856, 3872, 3888, 3904, 3920, 3936, 3952, 3968, 3984, 4000, 4016, 4032,
    4048, 4064, 4080, 4096, 4112, 4128, 4144, 4160, 4176, 4192, 4208, 4224,
    4240, 4256, 4272, 4288, 4304, 4320, 4336, 4352, 4368, 4384, 4400, 4416,
    4432, 4448, 4464, 4480, 4496, 4512, 4528, 4544, 4560, 4576, 4592, 4608,
    4624, 4640, 4656, 4672, 4688, 4704, 4720, 4736, 4752, 4768, 4784, 4800,
    4816, 4832, 4848, 4864, 4880, 4896, 4912, 4928, 4944, 4960, 4976, 4992,
    5008, 5024, 5040, 5056, 5072, 5088, 5104, 5120, 5136, 5152, 5168, 5184,
    5200, 5216, 5232, 5248, 5264, 5280, 5296};

class Melody {
private:
  bool m_vibrato;
  int state;
  const int m_pin;

  inline double eqlTemp(int note) { return pow(2, note / 12.0) * 440; }

  int findTiming(double x) {
    // using binary search
    // but first check neighbors of last match
    // let 'a' be the first boundary and 'b' the second boundary.
    // if a <= x < b, then return index of a.

    // https://www.desmos.com/calculator/bx3mc2wgya

    // LENGTH without -1 because accumulative is one number larger
    int a = 0, b = len();
    while (b - a > 1) {
      int mid = (a + b) / 2;
      if (timing(mid) < x && b - mid >= 1) {
        a = mid;
      } else if (timing(mid) >= x && mid - a >= 1) {
        b = mid;
      }
    }
    return a;
  }

  int note(int index) {
    if (state == 1) {
      return notes1[index];
    } else {
      return notes2[index];
    }
  }

  int timing(int index) {
    if (state == 1) {
      return timing1[index];
    } else {
      return timing2[index];
    }
  }

  int rhythm(int index) {
    if (state == 1) {
      return rhythm1[index];
    } else {
      return (index ? 16 : 32);
    }
  }

  bool isNotRest(int index) {
    if (state == 1) {
      return restField1[index];
    } else {
      return index != 0;
    }
  }

  int len() {
    if (state == 1) {
      return LEN1;
    } else {
      return LEN2;
    }
  }

public:
  Melody(bool vibrato, int pin) : state(0), m_vibrato(false), m_pin(pin) {
    int total = 0;
  }

  ~Melody() {}

  void toggle() {
    state = (state + 1) % 3;
    if (state == 0) {
      noTone(m_pin);
    }
  }

  bool getTone(int time) {
    if (state == 0)
      return false;
    static int lastIndex = 0;
    int index = findTiming(time * BEAT_UNIT);
    if (lastIndex != index) {
      if (isNotRest(index)) {
        tone(m_pin, eqlTemp(note(index)));
      } else {
        noTone(m_pin);
      }
    }
    lastIndex = index;
    return time * BEAT_UNIT < timing(len());
  }
};
