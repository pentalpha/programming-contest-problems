#include <iostream>
#include <vector>

using namespace std;

struct Interval{
	int start;
	int end;
};

bool intervalContains(Interval x, int a){
	return (a >= x.start || a <= x.end);
}

int main(int argc, char const *argv[])
{
	while(true){
		int nSoldiers, nLosses;
		vector<Interval> attackLine;
		cin >> nSoldiers >> nLosses;
		if(nSoldiers == 0 && nLosses == 0){
			break;
		}
		Interval generalInterval;
		generalInterval.start = 1;
		generalInterval.end = nSoldiers;
		attackLine.push_back(generalInterval);
		while(nLosses > 0){
			int start, end;
			cin >> start >> end;
			int sInterval = -1, eInterval = -1;
			std::vector<Interval> newAttackLine;
			for(int i = 0; i < attackLine.size(); i++){
				if(intervalContains(interval, start)){
					sInterval = i;
				}
				if(intervalContains(interval, end)){
					eInterval = i;
				}
				if(sInterval == eInterval){
					newAttackLine = attackLine;
					if(start == attackLine[sInterval].start && end == attackLine[sInterval].end){
						newAttackLine[sInterval].
					}
				}
			}



			nLosses--;
		}
		cout << "-\n";
	}
	return 0;
}