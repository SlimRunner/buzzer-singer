#pragma once

constexpr int LENGTH = 62;

constexpr int notRests[LENGTH] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

constexpr int notes[LENGTH] = {
    0, -5, 5, 3, -4, -2, 0, -2, 0, 8, 7, 5,  3, -2, 0,  2,  3,  7,  8,  7, 0,
    0, 3,  5, 7, 10, 8,  7, 5,  7, 4, 8, 7,  5, 8,  12, 14, 12, 10, 8,  7, 5,
    3, -2, 0, 2, 3,  7,  8, 7,  0, 0, 3, -1, 3, 2,  10, 5,  8,  7,  -2, 3};

constexpr int rhythm[LENGTH] = {
    128, 64, 16, 48,  16, 16,  16, 64, 48, 16, 16, 16, 32, 32, 32, 32,
    48,  80, 16, 16,  64, 112, 32, 16, 48, 32, 32, 32, 32, 48, 32, 16,
    16,  32, 16, 16,  32, 16,  64, 16, 16, 16, 32, 32, 32, 32, 48, 80,
    16,  16, 64, 112, 32, 16,  48, 32, 32, 32, 32, 32, 16, 64};

int frequencies[LENGTH];
int timing[LENGTH + 1];

double eqlTemp(int note) {
  return pow(2, note / 12.0) * 440;
}

int getDuration() {
  int total = 0;
  for (int i = 0; i < LENGTH; ++i) {
    total += rhythm[i];
  }
  return total;
}

void initFrequencies() {
  for (int i = 0; i < LENGTH; ++i) {
    frequencies[i] = eqlTemp(notes[i]);
  }
}

void initCumulative() {
  int total = 0;
  for (int i = 0; i <= LENGTH; ++i) {
    total += rhythm[i];
    timing[i + 1] = total;
  }
  timing[0] = 0;
}

int findTiming(double x) {
  // using binary search
  // but first check neighbors of last match
  // let 'a' be the first boundary and 'b' the second boundary.
  // if a <= x < b, then return index of a.

  // https://www.desmos.com/calculator/bx3mc2wgya

  // LENGTH without -1 because accumulative is one number larger
  int a = 0, b = LENGTH;
  while (b - a > 1) {
    int mid = (a + b) / 2;
    if (timing[mid] < x && b - mid >= 1) {
      a = mid;
    } else if (timing[mid] >= x && mid - a >= 1) {
      b = mid;
    }
  }
  return a;
}

const int duration = getDuration();

void setup() {
  Serial.begin(9600);
  initFrequencies();
  initCumulative();
}

void loop() {
  constexpr double conversion = 32 * 128.0 / 60000.0;
  unsigned long timer = millis() * conversion;
  int index = findTiming(timer);
  if (notRests[index]) {
    tone(7, eqlTemp(notes[index]));
  } else {
    noTone(7);
  }
}