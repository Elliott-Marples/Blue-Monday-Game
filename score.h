#ifndef BLUE_MONDAY_SCORE_H_
#define BLUE_MONDAY_SCORE_H_



class Player;

class Score {
public:
	Score();

	int value;

	Player* parent;

	void Init();
	void Increment();
	void Prolong();
};

#endif // !BLUE_MONDAY_SCORE_H_
