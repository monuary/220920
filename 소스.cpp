//구조체의 이점 : 연관있는 데이터를 하나로 묶으면 프로그램의 구현 및 관리가 용이하다.
//소프트웨어 = 데이터의 표현 + 데이터의 처리 -> 데이터는 생성, 이동, 소멸된다. 따라서 구조체는 용이하다.

#include<iostream>
using namespace std;

#define ID_LEN		20
#define MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car
{
	char gamerID[ID_LEN];	//	소유자ID
	int fuelGauge;			//	연료량
	int curSpeed;			//	현재속도
};

void ShowCarState(const Car& car)	//	참조자로 외부 변수에 변화를 준다. 구조체 Car에 종속시켰지만, 다른 영역에서 호출할 가능성이 없는 것은 아니다.
//	그래서 함수를 구조체에 포함시키는 방법도 있다.
{
	cout << "소유자ID: " << car.gamerID << endl;
	cout << "연료량: " << car.fuelGauge << "%" << endl;
	cout << "현재속도: " << car.curSpeed << "km/s" << endl << endl;
}

void Accel(Car& car)
{
	if (car.fuelGauge <= 0)
		return;						//	연료가 없기 때문에 가속 불가
	else
		car.fuelGauge -= FUEL_STEP;	//연료 2퍼 감소

	if (car.curSpeed + ACC_STEP >= MAX_SPD)
	{
		car.curSpeed = MAX_SPD;		//	최대 속도 시, 악셀을 밟아도 연료만 줄어들 뿐
		return;						//	return 시, 함수에서 탈출한다.
	}

	car.curSpeed += ACC_STEP;
}

void Break(Car& car)
{
	if (car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;	//	현재 속도가 10km/s 아래일 때, 속도가 0km/s가 된다.
		return;
	}

	car.curSpeed -= BRK_STEP;
}

int main()
{
	Car run99 = { "run99",100,0 };
	Accel(run99);
	Accel(run99);	//	두 번 악셀
	ShowCarState(run99);
	Break(run99);
	ShowCarState(run99);

	Car sped77 = { "sped77",100,0 };
	Accel(sped77);
	Break(sped77);	//	연료만 2퍼 줄어든 것을 관찰 가능
	ShowCarState(sped77);
	return 0;
}