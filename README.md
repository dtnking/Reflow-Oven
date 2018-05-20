# Reflow-Oven

### TRIAC
TRIAC is an three-terminal semiconductor device to control current flow. When triggered, it allows current to conduct through it in either direction. We are experimenting the property of TRIAC to further understand how it works pratically.

![schematic](https://user-images.githubusercontent.com/26379432/40277225-f3b5d9fc-5c4d-11e8-922d-b714f0790bd0.PNG) <br />
Above is the schematic of how we constructed our circuit. Here, we are using **BT134-600E** as our testing target. The **Vramp** is connected to a Waveform Function Generator that can produce ramp up voltage in burst mode. We only need to observe what happened when Vgt reached the trigger point which in our case is maximum 1V based on datasheet. We are using two 27Ω resistor connecting in parallel to get 14Ω to distribute the power dissipation between the two as our resistors can not withstand long time of high power. However, the resistors get hot quickly aswell, so we need to make sure the power supply is turned off once the waveform is captured in our oscilloscope.<br /><br />

![](https://user-images.githubusercontent.com/26379432/40245429-3eb19a24-5af8-11e8-823c-d9436cc7ca19.PNG)
