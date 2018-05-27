# Reflow-Oven

## TRIAC
TRIAC is an three-terminal semiconductor device to control current flow. When triggered, it allows current to conduct through it in either direction. The objective of this experiment is to study the property of TRIAC and understand how it works pratically.<br />

![schematic custom](https://user-images.githubusercontent.com/26379432/40280682-b338072e-5c89-11e8-8b50-42dd9d930ec4.png)<br />

Above is the schematic of how we constructed our circuit. Here, **BT134-600E** is used as the testing TRIAC. The **V<sub>R</sub>** is connected to a Waveform Function Generator that can produce ramp up voltage in burst mode. Observation is made when V<sub>GT</sub> reached the trigger point which in the case is maximum 1V based on datasheet. As for the load resistor, **R<sub>load</sub>**, two 27Ω resistors are used to connect in parallel to get 14Ω to distribute the power dissipation between the two as our resistors can not withstand long time of high power. However, the resistors still get hot quickly, so it is a need to make sure the time of power supply turned on is short to prevent the resistors burn up. The **R<sub>1</sub>** resistor is to limit the current flows into the gate of the TRIAC, 200Ω is used in the experiment but any value will do just that be awared that the current, I<sub>GT</sub> must be enough to trigger the TRIAC. **V<sub>s</sub>** is connected to the DC power supply providing 9V voltage and 500mA of current. Please be aware the current that flows through the TRIAC, I<sub>T</sub>, must not violating the rating current of the TRIAC.<br /><br />

![quadrant definition](https://user-images.githubusercontent.com/26379432/40282026-3e706e06-5c9b-11e8-8196-f220596540b5.png)<br />
TRIAC has four different modes which can refer from above, to get one of the mode to operate, the direction of the current flow into the gate and MT2 of the TRIAC must be matched. Below shown the place where we probed the signals.<br /><br />
![probelocation](https://user-images.githubusercontent.com/26379432/40281682-54700fa8-5c97-11e8-8a8b-b2b2bb9c66fa.png)<br /><br /><br />

Each mode has different output result: Quadrant 1, Quadrant 2, Quadrant 3 and Quadrant 4. The main objective of the experiment here is to check whether the TRIAC is activated when sufficient V<sub>GT</sub> is applied. By looking at the V<sub>T</sub>,  it can be tell whether the TRIAC is being activated. So the main focus here is V<sub>T</sub> and V<sub>GT</sub>, if V<sub>GT</sub> ramped up to sufficient value, V<sub>T</sub> should drop as the current, I<sub>T</sub> is conducting through the TRIAC. <br /><br />

### Quadrant 1 ( MT2 :+ve, I<sub>GT</sub> :+ve ):
![q1 result](https://user-images.githubusercontent.com/26379432/40281636-eb0573dc-5c96-11e8-892e-bd32383d78ea.png)<br />
As see from the waveform above, the V<sub>T</sub> drop from 9V to 1.7V when V<sub>GT</sub> ramped up to 0.8V which is the trigger voltage.<br /><br /><br /><br />

### Quadrant 2 ( MT2 :+ve, I<sub>GT</sub> :-ve ):
![q2 result](https://user-images.githubusercontent.com/26379432/40281607-b4070de6-5c96-11e8-80a3-2dcd49c811a4.png)<br />
The V<sub>T</sub> drop from 9V to 1.7V when V<sub>GT</sub> ramped up to -0.7V.<br /><br /><br /><br />

### Quadrant 3 ( MT2 :-ve, I<sub>GT</sub> :-ve ):
![q3 result](https://user-images.githubusercontent.com/26379432/40281649-14816b80-5c97-11e8-831f-59666c54c0a9.png)<br />
The V<sub>T</sub> drop from -9V to -1.7V when V<sub>GT</sub> ramped up to -0.9V.<br /><br /><br /><br />

### Quadrant 4 ( MT2 :-ve, I<sub>GT</sub> :+ve ):
![q4 result](https://user-images.githubusercontent.com/26379432/40281510-877ff5b8-5c95-11e8-9ee5-3ddef05eef67.png)<br />
The V<sub>T</sub> drop from -9V to -1.7V when V<sub>GT</sub> ramped up to 0.75V.<br /><br /><br />

# Reference
1. https://www.edaboard.com/showthread.php?86588-What-kind-of-triac-should-I-use-with-this-light-dimmer-circuit
