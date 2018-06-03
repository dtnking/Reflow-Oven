# Reflow-Oven

# 1. TRIAC
TRIAC is an three-terminal semiconductor device to control current flow. When triggered, it allows current to conduct through it in either direction. The objective of this experiment is to study the property of TRIAC and understand how it works pratically.<br />

## 1.1 Schematic
![schematic custom](https://user-images.githubusercontent.com/26379432/40280682-b338072e-5c89-11e8-8b50-42dd9d930ec4.png)<br />

Above is the schematic of how we constructed our circuit. Here, **BT134-600E** is used as the testing TRIAC. The **V<sub>R</sub>** is connected to a Waveform Function Generator that can produce ramp up voltage in burst mode. Observation is made when V<sub>GT</sub> reached the trigger point which in the case is maximum 1V based on datasheet. As for the load resistor, **R<sub>load</sub>**, two 27Ω resistors are used to connect in parallel to get 14Ω to distribute the power dissipation between the two as our resistors can not withstand long time of high power. However, the resistors still get hot quickly, so it is a need to make sure the time of power supply turned on is short to prevent the resistors burn up. The **R<sub>1</sub>** resistor is to limit the current flows into the gate of the TRIAC, 200Ω is used in the experiment but any value will do just that be awared that the current, I<sub>GT</sub> must be enough to trigger the TRIAC. **V<sub>s</sub>** is connected to the DC power supply providing 9V voltage and 500mA of current. Please be aware the current that flows through the TRIAC, I<sub>T</sub>, must not violating the rating current of the TRIAC.<br /><br />

## 1.2 TRIAC's Quadrants
![quadrant definition](https://user-images.githubusercontent.com/26379432/40282026-3e706e06-5c9b-11e8-8196-f220596540b5.png)<br />
TRIAC has four different modes which can refer from above, to get one of the mode to operate, the direction of the current flow into the gate and MT2 of the TRIAC must be matched. <br /><br />

 

Each mode has different output result: Quadrant 1, Quadrant 2, Quadrant 3 and Quadrant 4. The main objective of the experiment here is to check whether the TRIAC is activated when sufficient V<sub>GT</sub> is applied. By looking at the V<sub>T</sub>,  it can be tell whether the TRIAC is being activated. So the main focus here is V<sub>T</sub> and V<sub>GT</sub>, if V<sub>GT</sub> ramped up to sufficient value, V<sub>T</sub> should drop as the current, I<sub>T</sub> is conducting through the TRIAC. <br /><br />

### Quadrant 1 ( MT2 :+ve, I<sub>GT</sub> :+ve ):
![result of quadrant 1](https://user-images.githubusercontent.com/26379432/40884504-4b6cb09a-6747-11e8-9217-a4a633cb7df6.png)<br />The image above shows how the circuit is constructed and the place of the signal probed. Positive voltage is feed into MT2 and <sub>GT</sub> in Quadrant 1.
![explanation of q1](https://user-images.githubusercontent.com/26379432/40884744-0410bb42-674c-11e8-8c06-f81058c11807.png)<br />
As see from the waveform above, the V<sub>T</sub> drop from 9V to 1.7V when V<sub>GT</sub> ramped up to 0.8V which is the trigger voltage. V<sub>T</sub> drops mean that the current is flowing through the TRIAC which is then showed that the TRIAC is being activated. <br /><br /><br /><br />

### Quadrant 2 ( MT2 :+ve, I<sub>GT</sub> :-ve ):
![q2 result](https://user-images.githubusercontent.com/26379432/40884424-e74dbad8-6745-11e8-84f1-9b898794bb6b.png)<br />
Note that negative voltage is supplied into the V<sub>GT</sub> while postive voltage is supplied to MT2 in this quadrant.
![explanation of q2](https://user-images.githubusercontent.com/26379432/40884877-61d4599e-674e-11e8-8fe0-4ea3305f810d.png)<br />
The V<sub>T</sub> drop from 9V to 1.7V when V<sub>GT</sub> ramped up to -0.7V. In this quadrant, current flows through the TRIAC when the V<sub>GT</sub> is -0.7V, which is needed to trigger the TRIAC to activate. <br /><br /><br /><br />

### Quadrant 3 ( MT2 :-ve, I<sub>GT</sub> :-ve ):
![result of quadrant 3](https://user-images.githubusercontent.com/26379432/40884507-51a60024-6747-11e8-9b29-4eea449f9119.png)<br />
In order to use this quadrant, negative voltage is supplied into both MT2 and also V<sub>GT</sub>.
![explanation of q3](https://user-images.githubusercontent.com/26379432/40885055-fe2ea800-6751-11e8-8e4c-a2bb5ff9fd70.png)<br />
The V<sub>T</sub> drop from -9V to -1.7V when V<sub>GT</sub> ramped up to -0.9V. So it is obvious that the trigger gate voltage in this quadrant is -0.9V. The TRIAC is activated on as the current is passing through it.<br /><br /><br /><br />

### Quadrant 4 ( MT2 :-ve, I<sub>GT</sub> :+ve ):
![result of quadrant 4](https://user-images.githubusercontent.com/26379432/40884508-67283f8e-6747-11e8-9cfb-b86911d04aa4.png)<br />
Negative voltage is supplied to MT2 whereas positive voltage is supplied to V<sub>GT</sub>, to able to see the correct waveform.
![explanation of q4](https://user-images.githubusercontent.com/26379432/40885136-26dc0b0c-6753-11e8-83dc-82e476264e90.png)<br />
The V<sub>T</sub> drop from -9V to -1.7V when V<sub>GT</sub> ramped up to 0.8V. To be able to activate the TRIAC in quadrant 4, the voltage trigger must be 0.8V above. The voltage drop of V<sub>T</sub> shows that the current is flowing through the TRIAC.<br /><br /><br />

# 1.3 Problem Faced
As noticed from the waveform above, a distortion occurs after the TRIAC is activated. This is due to the function generator is not able to sink that much of current in that much of period of time. <br /><br /><br />
![distortion](https://user-images.githubusercontent.com/26379432/40885451-cf93bd8a-6758-11e8-91bc-de8173a4ce54.png)
A voltage power follower can be created to solve this problem.

# 1.4 Reference
1. https://www.edaboard.com/showthread.php?86588-What-kind-of-triac-should-I-use-with-this-light-dimmer-circuit
