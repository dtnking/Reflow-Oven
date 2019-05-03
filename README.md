# Reflow-Oven
Reflow oven is used to reflow soldering of surface-mounted electronic components to printed circuit board. Reflow soldering is the mechanism that used to assemble most printed circuit board these days. It enables mass production at a very rapid rate by allowing the placement of components to be separated from the actual soldering process. 

In reflow soldering, the pads of the printed circuit board are first applied with solder paste in a pattern using stencil so that it leaves solder paste only. Solder paste is a mixture of flux and solder which is sticky to allow the component be placed on it and held remain. When all of the components are in place on the printed circuit board, the board is then placed into the reflow oven where it is raised to a temperature above the melting point of the solder. The solder then reflows onto the terminal of the components and allowed to cool. At that point, all the components are attached simulateneously.

Reflowing the solder is an alternative way from hand soldering. When hand soldering, components are being treated individually and applying heat at a same time. By constructing a reflow oven, users are able to fabricate printed circuit board by themselves without sending out their design to fabrication house which will spent a lot of time and money. 

Reflow oven needs to be temperature controlled. Here, TRIAC is used in the system to control the power delivered to the heating element. It involves a lot of power electronics. To heat up the heating elements, it needs large amount of power which involves high voltage and current. Extreme care and safety must at the highest priority. Thus safety circuit is very important to prevent any accident occurs. On the PC side, a GUI for power controlling and temperature monitoring is created.

Here is the internal circuit of the original baker oven that is not yet being customized to reflow oven.<br /><br />
<img src="https://user-images.githubusercontent.com/26379432/41049857-6e13de6c-69e4-11e8-9ebe-17f00688b03b.png" height="400" width="600"><br />



# 1. TRIAC
TRIAC is an three-terminal semiconductor device to control current flow. When triggered, it allows current to conduct through it in either direction. The objective of this experiment is to study the property of TRIAC and understand how it works pratically.<br />

## 1.1 Schematic
<img src="https://user-images.githubusercontent.com/26379432/40280682-b338072e-5c89-11e8-8b50-42dd9d930ec4.png" height="250" width="350">


Above is the schematic of how we constructed our circuit. Here, **BT134-600E** is used as the testing TRIAC. The **V<sub>R</sub>** is connected to a Waveform Function Generator that can produce ramp up voltage in burst mode. Observation is made when V<sub>GT</sub> reached the trigger point which in the case is maximum 1V based on datasheet. As for the load resistor, **R<sub>load</sub>**, two 27Ω resistors are used to connect in parallel to get 14Ω to distribute the power dissipation between the two as our resistors can not withstand long time of high power. However, the resistors still get hot quickly, so it is a need to make sure the time of power supply turned on is short to prevent the resistors burn up. The **R<sub>1</sub>** resistor is to limit the current flows into the gate of the TRIAC, 200Ω is used in the experiment but any value will do just that be awared that the current, I<sub>GT</sub> must be enough to trigger the TRIAC. **V<sub>s</sub>** is connected to the DC power supply providing 9V voltage and 500mA of current. Please be aware the current that flows through the TRIAC, I<sub>T</sub>, must not violating the rating current of the TRIAC.<br /><br />

## 1.2 TRIAC's Quadrants
<img src="https://user-images.githubusercontent.com/26379432/40282026-3e706e06-5c9b-11e8-8196-f220596540b5.png" height="350" width="350"><br />
TRIAC has four different modes which can refer from above, to get one of the mode to operate, the direction of the current flow into the gate and MT2 of the TRIAC must be matched. <br />

Each mode has different output result: Quadrant 1, Quadrant 2, Quadrant 3 and Quadrant 4. The main objective of the experiment here is to check whether the TRIAC is activated when sufficient V<sub>GT</sub> is applied. By looking at the V<sub>T</sub>,  it can be tell whether the TRIAC is being activated. So the main focus here is V<sub>T</sub> and V<sub>GT</sub>, if V<sub>GT</sub> ramped up to sufficient value, V<sub>T</sub> should drop as the current, I<sub>T</sub> is conducting through the TRIAC. <br /><br />

### Quadrant 1 ( MT2 :+ve, I<sub>GT</sub> :+ve ):
![result of quadrant 1](https://user-images.githubusercontent.com/26379432/40884504-4b6cb09a-6747-11e8-9217-a4a633cb7df6.png)<br /><br />
The image above shows how the circuit is constructed and the place of the signal probed. Positive voltage is feed into MT2 and <sub>GT</sub> in Quadrant 1.<br /><br />
<img src="https://user-images.githubusercontent.com/26379432/40884744-0410bb42-674c-11e8-8c06-f81058c11807.png" height="300" width="400"><br />
As see from the waveform above, the V<sub>T</sub> drop from 9V to 1.7V when V<sub>GT</sub> ramped up to 0.8V which is the trigger voltage. V<sub>T</sub> drops mean that the current is flowing through the TRIAC which is then showed that the TRIAC is being activated. <br /><br /><br /><br />

### Quadrant 2 ( MT2 :+ve, I<sub>GT</sub> :-ve ):
![q2 result](https://user-images.githubusercontent.com/26379432/40884424-e74dbad8-6745-11e8-84f1-9b898794bb6b.png)<br /><br />
Note that negative voltage is supplied into the V<sub>GT</sub> while postive voltage is supplied to MT2 in this quadrant.<br /><br />
<img src="https://user-images.githubusercontent.com/26379432/40884877-61d4599e-674e-11e8-8fe0-4ea3305f810d.png" height="300" width="400"><br />
The V<sub>T</sub> drop from 9V to 1.7V when V<sub>GT</sub> ramped up to -0.7V. In this quadrant, current flows through the TRIAC when the V<sub>GT</sub> is -0.7V, which is needed to trigger the TRIAC to activate. <br /><br /><br /><br />

### Quadrant 3 ( MT2 :-ve, I<sub>GT</sub> :-ve ):
![result of quadrant 3](https://user-images.githubusercontent.com/26379432/40884507-51a60024-6747-11e8-9b29-4eea449f9119.png)<br /><br />
In order to use this quadrant, negative voltage is supplied into both MT2 and also V<sub>GT</sub>.<br /><br />
<img src="https://user-images.githubusercontent.com/26379432/40885055-fe2ea800-6751-11e8-8e4c-a2bb5ff9fd70.png" height="300" width="400"><br />
The V<sub>T</sub> drop from -9V to -1.7V when V<sub>GT</sub> ramped up to -0.9V. So it is obvious that the trigger gate voltage in this quadrant is -0.9V. The TRIAC is activated on as the current is passing through it.<br /><br /><br /><br />

### Quadrant 4 ( MT2 :-ve, I<sub>GT</sub> :+ve ):
![result of quadrant 4](https://user-images.githubusercontent.com/26379432/40884508-67283f8e-6747-11e8-9cfb-b86911d04aa4.png)<br /><br />
Negative voltage is supplied to MT2 whereas positive voltage is supplied to V<sub>GT</sub>, to able to see the correct waveform.<br /><br />
<img src="https://user-images.githubusercontent.com/26379432/40885136-26dc0b0c-6753-11e8-83dc-82e476264e90.png" height="300" width="400"><br />
The V<sub>T</sub> drop from -9V to -1.7V when V<sub>GT</sub> ramped up to 0.8V. To be able to activate the TRIAC in quadrant 4, the voltage trigger must be 0.8V above. The voltage drop of V<sub>T</sub> shows that the current is flowing through the TRIAC.<br /><br /><br />

# 1.3 Problem Faced
As noticed from the waveform above, a distortion occurs after the TRIAC is activated. This is due to the function generator is not able to sink that much of current in that much of period of time. <br /><br /><br />
<img src="https://user-images.githubusercontent.com/26379432/40885451-cf93bd8a-6758-11e8-91bc-de8173a4ce54.png" height="400" width="800"><br />
The problem is not a big deal as the values are captured before the distortions happen. However, a voltage power follower can be created to solve this problem.

# 1.4 References
1. https://www.edaboard.com/showthread.php?86588-What-kind-of-triac-should-I-use-with-this-light-dimmer-circuit<br />
2. http://www.ween-semi.com/documents/BT134-600E.pdf (Datasheet of BT134-600E)<br /><br /><br />



# 2. Zero-Crossing circuit
Zero-cross circuit is used to detect when the voltage is crossing zero on AC signal. This is very useful to control when to activate the TRIAC depending on the purpose.
## 2.1 Opto-coupler
Opto-coupler or opto-isolator is used to isolate the high voltage and low voltage. Opto-coupler consist of a LED that emits infra-red light and a photo-sensitive semiconductor device to receive the signal. There are many cases where in a same circuit, may consist high voltage area and low voltage area to drive the respective components.  In order to protect the components (if something went wrong) from the circuit that used low voltage, an opto-coupler is used.
## 2.2 Schematic
![schematic-zerocrossing custom](https://user-images.githubusercontent.com/26379432/40888098-d577d142-6784-11e8-8257-8b30b06fb9f7.png)
<br /><br />
The schematic above shows how the circuit is constructed. V<sub>cc</sub> is connected to a step-down transformer to step down 240V<sub>AC</sub> to a safer voltage 12V<sub>RMS</sub>. The opto-coupler used here is **4N25** to isolate the high voltage from directly input into the MCU(MCU can only receives 3.3V signals) . The left side of the opto-coupler is high voltage and the right side of it is driving low voltage which is needed to connect to the MCU. The R<sub>c</sub> is the pull-up resistor that when BJT inside the optocoupler is not saturated, micocontroller will receive a HIGH and when the BJT is saturated, microcontroller will receive a LOW. The circuit on the left is constructed such a way that to suit the requirement of the optocoupler. In order to ease the calculation of the value of resistors R<sub>A</sub>, R<sub>B</sub>, and R<sub>D</sub>, two equivalent circuits is made: forward and reverse bias (because it is AC signals).<br />
## 2.3 Equations
First, take a look on the reverse bias as it is simpler.<br /><br /><br />
<img src="https://user-images.githubusercontent.com/26379432/40889363-efe55b5e-6797-11e8-8f3c-fa3fbb27192d.png" height="230" width="330"><br /><br />
The above shows the equivalent circuit. There is no need to consider R<sub>D</sub> as no current will flow in to the LED of the optocoupler. Take notice that V<sub>x</sub> - V<sub>y</sub> must be less than the maximum rating of the reverse voltage of 4N25 optocoupler which is 5V. <br /><br />
![capture1](https://user-images.githubusercontent.com/26379432/40889325-55fc2446-6797-11e8-8f4d-281a196e7cd4.PNG)<br /><br /><br />

Next, let's go on to the forward bias circuit.<br /><br /><br />
<img src="https://user-images.githubusercontent.com/26379432/40889360-ec7ef1aa-6797-11e8-869b-7585faca4acc.png" height="250" width="480"><br /><br />
Here, the optocoupler is replaced by an power supply as assumption is made that the LED consumes 1.2V. Also, 50mA of current is needed to flow into R<sub>D</sub> to drive the LED (differs when using different optocoupler).  Assume the V<sub>y</sub>-V<sub>x</sub> is 2V (assumption must be logical).  R<sub>D</sub>=2-1.2<br /><br />
![capture2](https://user-images.githubusercontent.com/26379432/40889617-82b4bcf0-679c-11e8-8f5f-712bc43c66f8.PNG)<br />
![capture4](https://user-images.githubusercontent.com/26379432/40889674-97ae8df6-679d-11e8-9f56-61b3024a2038.PNG)<br /><br />
By having the value of R<sub>A</sub>, R<sub>B</sub> can be calculated by substituting R<sub>A</sub> into Equation (12). Also, R<sub>D</sub> can be calculated easily by using the equation below.<br /><br />
![capture5](https://user-images.githubusercontent.com/26379432/40889801-4dfa91d0-679f-11e8-8131-21776ad7a65b.PNG)<br /><br />
The values of R<sub>A</sub> and R<sub>B</sub> may not be a valid resistance value available. Therefore, a smaller value nearest to the calculated of R<sub>A</sub> and a bigger value nearest to the calculated of R<sub>B</sub> can be applied.<br /><br /><br />
# 2.4 References
1. https://www.vishay.com/docs/83725/4n25.pdf (Datasheet of 4N25)
