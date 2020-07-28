#ifndef ENUMY_H
#define ENUMY_H

enum direction {
    up = 1,
    rightDir,
    down,
    leftDir
};

enum motionMode {
  isAuto = 1,
  isHuman,
  isShortest,
  isBFS,
  isDFS,
};

enum motionScore {
  empty = -1,
  wallorbarrier = -100,
  headOfSnake = 0,
  wunszyc = -100,
  food = 100
};

enum barrierKind {
    square = 1,
    lShape,
    cShape
};

enum tileSize {
	w = 10,
	h = 10
};

enum cost {
	hightCost = 10000,
	lowCost = 0
};

enum speed {
	snake = 200,
	prize = 400000,
	alg = 50
};

enum startPosition {
	x = 150,
	y = 150
};

#endif // ENUMY_H
