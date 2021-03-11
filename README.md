# ABS-Controller
ABS(Anti lock Braking System) using longitudinal dynamics

1. Longitudinal model (종방향)

![fbd_vehicle](https://user-images.githubusercontent.com/79674592/110263256-7adfbe80-7ff9-11eb-9783-080b9f42e1d5.PNG)

차량 동역학은 크게 종방향,횡방향,수직방향으로 나뉘는데 이 3가지의 움직임은 독립적이지 않다. ABS 컨트롤러의 성능을 검증하기 위해 사용한 차량동역학 모델을 사용하였다.

- Vehicle dynamics equation

위 자유물체도를 기반으로 vehicle dynamics 방정식을 세워보면 다음과 같다. 
![vehicle_eq](https://user-images.githubusercontent.com/79674592/110263780-073eb100-7ffb-11eb-9da8-120c2f9de80f.PNG)

뉴턴의 운동법칙을 이용한 평형식이며 Froad는 차량이 앞으로 나아가는 traction force를 의미하고 Froll은 앞바퀴와 뒷바퀴에서 발생하는 구름저항을 의미한다. Fair는 공기저항을 의미하고 Mgsin(theta)는 경사에 의한 힘으로 나누었다.

- Wheel Dynamics equation

휠에서는 회전운동이 발생하기 때문에 필히 관성모멘트가 존재한다. 관성모멘트와 토크의 관계는 다음과 같이 나타낼 수 있다. ![inerita_eq](https://user-images.githubusercontent.com/79674592/110264252-3c97ce80-7ffc-11eb-9674-4ddf3a6d67a3.PNG)

이를 기반으로 Wheel Dynamics 방정식은 다음과 같이 도출할 수 있다.
![wheel_eq](https://user-images.githubusercontent.com/79674592/110264413-95fffd80-7ffc-11eb-9582-58d376cff10b.PNG)

Tshaft는 엔진에서 발생한 출력이 shaft를 통해 전달되는 토크이고 Brake는 제동시 발생하는 토크를 의미한다. 마지막으로 (heff * Froad)는 지면과의 접촉에서 발생한 마찰력을 의미한다.

- Tire model

![tire](https://user-images.githubusercontent.com/79674592/110266212-ac0fbd00-8000-11eb-8e76-dce8f3d38e68.PNG)

출력이 각각의 구동계를 거쳐 최종으로 타이어를 지나게 되면 Traction Force가 발생하게 된다. 해당 종방향 모델에서는 Bakker - Pacejka의 Magic Tire Formula 공식을 이용하여 Froad를 정의한다.
![froad_eq](https://user-images.githubusercontent.com/79674592/110265147-40c4eb80-7ffe-11eb-81da-1eca85d4f53c.PNG)

해당 공식을 사용하기 위해 Tire에서 발생하는 slip ratio는 다음과 같이 정의한다.

![slip_eq](https://user-images.githubusercontent.com/79674592/110265266-8a153b00-7ffe-11eb-9068-7ee87667205b.PNG)

v는 차량 body의 속도를 의미하며 가속시 w가 커지면서 slip이 증가하게 되고 제동시 w가 줄어 slip이 줄게된다. ratio를 구하기 위해 hw-v가 0보다 큰 경우 hw로 나누게 되고 반대인 경우 v로 나누게 된다.

- Brake model

![brake_Eq](https://user-images.githubusercontent.com/79674592/110267728-baaba380-8003-11eb-9155-2f75abcb092c.PNG)

![brake spec](https://user-images.githubusercontent.com/79674592/110272789-5e01b600-800e-11eb-88e8-d5904c2e4abd.PNG)

브레이크 로직은 다음과 같다. 유압식 브레이크는 브레이크를 밟는 압력(Pw)이 브레이크 피스톤을 밀어내고 있는 스프링 압력(Ppo)보다 더 커야 브레이크 토크가 발생하게 된다. 또한 브레이크 레버를 밟는 힘은 유압의 힘으로 전환되기까지 일정기간의 Delay가 존재하고 브레이크의 압력은 First order Transfer-Function에 따라 브레이크 압력이 부드럽게 증가한다.
기어의 경우 특정 속도값들을 임계점으로 두어 속도에 따라 기어비가 변하게 설계하였고, 엔진의 경우 간단하게 스로틀 각과 엔진의 회전수에 따라 토크를 mapping하였다.

2. ABS controller

- 도로환경

![hw2_1_result](https://user-images.githubusercontent.com/79674592/110786170-26fdff80-82af-11eb-829b-ccce800bd0c9.png)


위 사진은 날씨에 따라 도로의 환경이 달라지는 특성을 반영한 것이다. ABS의 목적은 가장 최대정지마찰계수를 얻는 지점에서의 slip을 유지하게 하여 차량이 미끄러지지 않고 조향이 되도록 주행하게 하는 것이다.그래프에서도 볼 수 있듯이 보편적으로 제동시 slip이 -5~-30% 일 때 최대정지마찰계수를 보이므로 이 slip값을 유지하도록 설계하였다.

![ABS](https://user-images.githubusercontent.com/79674592/110786034-003fc900-82af-11eb-8f51-3d37524cd675.PNG)
- ABS logic

![abs_logic](https://user-images.githubusercontent.com/79674592/110786046-03d35000-82af-11eb-87b8-d4eeee354c9a.PNG)

- Result

![dry_slip](https://user-images.githubusercontent.com/79674592/110786399-6debf500-82af-11eb-96ce-28b9ebbac34b.png)
![dry_speed](https://user-images.githubusercontent.com/79674592/110786408-704e4f00-82af-11eb-88e9-0e7fd832833a.png)

Dry condition에서는 ABS가 작동하지 않고 제동한 것을 확인 할 수 있다.

![wet_slip](https://user-images.githubusercontent.com/79674592/110786664-befbe900-82af-11eb-95c5-0c36f81a83bf.png)
![wet_speed](https://user-images.githubusercontent.com/79674592/110786676-c0c5ac80-82af-11eb-8709-c85f52215cc1.png)

Wet condition에서는 ABS가 작동하며 위에서 설계한 것과 같이 해당 slip의 경계를 유지하며 최대정지마찰계수를 유지하는 모습을 확인 할 수 있다.

![snow_slip](https://user-images.githubusercontent.com/79674592/110786995-2b76e800-82b0-11eb-9b2a-e37ad45ad333.png)
![snow_speed](https://user-images.githubusercontent.com/79674592/110786999-2dd94200-82b0-11eb-9b2a-c02471c50d7a.png)

Snow condition에서도 마찬가지로 위에서 설계한대로 ABS가 잘 작동한 것을 확인 할 수 있다. 하지만 Wet condition에 비해 slip 진동이 더 심해졌고 완전히 제동하는데 걸리는 시간도 더 오래걸렸다.

![ice_slip](https://user-images.githubusercontent.com/79674592/110788419-ee135a00-82b1-11eb-945c-2e36b857c90e.png)
![ice_speed](https://user-images.githubusercontent.com/79674592/110788428-f075b400-82b1-11eb-89b5-b2bf3370052a.png)


해당 조건에서도 정상적으로 ABS가 작동했다. 4가지 조건으로부터 공통적으로 얻을 수 있는 결과는 도로의 조건이 더 가혹해질수록 제동하는데 걸리는 시간이 더 길어지는 것을 확인 할 수 있었다. 하지만 모든 조건에서 설계한 slip의 임계값을 넘어가지 않고 잘 유지하며 제동한 것을 확인 할 수 있었다.
