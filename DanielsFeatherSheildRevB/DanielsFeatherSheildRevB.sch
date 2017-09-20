EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:l293d
LIBS:DanielsFeatherSheildRevB-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L L293D H-bridge1
U 1 1 5949C5D8
P 5350 2950
F 0 "H-bridge1" H 5350 3450 60  0000 C CNN
F 1 "L293D" H 5350 2450 60  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_Socket_LongPads" H 6550 3200 60  0001 C CNN
F 3 "" H 6550 3200 60  0001 C CNN
	1    5350 2950
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 LIR1
U 1 1 5949C62B
P 4650 1650
F 0 "LIR1" H 4650 1850 50  0000 C CNN
F 1 "CONN_01X03" V 4750 1650 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03_Pitch2.54mm" H 4650 1650 50  0001 C CNN
F 3 "" H 4650 1650 50  0001 C CNN
	1    4650 1650
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X03 CIR1
U 1 1 5949C66D
P 5100 1650
F 0 "CIR1" H 5100 1850 50  0000 C CNN
F 1 "CONN_01X03" V 5200 1650 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03_Pitch2.54mm" H 5100 1650 50  0001 C CNN
F 3 "" H 5100 1650 50  0001 C CNN
	1    5100 1650
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X03 RIR1
U 1 1 5949C692
P 5600 1650
F 0 "RIR1" H 5600 1850 50  0000 C CNN
F 1 "CONN_01X03" V 5700 1650 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03_Pitch2.54mm" H 5600 1650 50  0001 C CNN
F 3 "" H 5600 1650 50  0001 C CNN
	1    5600 1650
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X12 Feather(I/O_2)1
U 1 1 5949CA40
P 6950 2900
F 0 "Feather(I/O_2)1" H 6950 3550 50  0000 C CNN
F 1 "CONN_01X12" V 7050 2900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x12_Pitch2.54mm" H 6950 2900 50  0001 C CNN
F 3 "" H 6950 2900 50  0001 C CNN
	1    6950 2900
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X16 Feather(I/O_1)1
U 1 1 5949CA91
P 3500 2800
F 0 "Feather(I/O_1)1" H 3500 3650 50  0000 C CNN
F 1 "CONN_01X16" V 3600 2800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x16_Pitch2.54mm" H 3500 2800 50  0001 C CNN
F 3 "" H 3500 2800 50  0001 C CNN
	1    3500 2800
	-1   0    0    -1  
$EndComp
$Comp
L +3.3V #PWR01
U 1 1 5949CBFA
P 4000 2150
F 0 "#PWR01" H 4000 2000 50  0001 C CNN
F 1 "+3.3V" H 4000 2290 50  0000 C CNN
F 2 "" H 4000 2150 50  0001 C CNN
F 3 "" H 4000 2150 50  0001 C CNN
	1    4000 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 2150 3700 2150
$Comp
L GND #PWR02
U 1 1 5949CC39
P 4000 2350
F 0 "#PWR02" H 4000 2100 50  0001 C CNN
F 1 "GND" H 4000 2200 50  0000 C CNN
F 2 "" H 4000 2350 50  0001 C CNN
F 3 "" H 4000 2350 50  0001 C CNN
	1    4000 2350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4000 2350 3700 2350
Text GLabel 3700 2050 2    60   Input ~ 0
RESET
Text GLabel 3700 2250 2    60   Input ~ 0
ARF
Text GLabel 3700 2450 2    60   Input ~ 0
A0
Text GLabel 3700 2550 2    60   Input ~ 0
A1
Text GLabel 3700 2650 2    60   Input ~ 0
A2
Text GLabel 3700 2750 2    60   Input ~ 0
A3
Text GLabel 3700 2850 2    60   Input ~ 0
A4
Text GLabel 3700 2950 2    60   Input ~ 0
A5
Text GLabel 3700 3050 2    60   Input ~ 0
SCK
Text GLabel 3700 3150 2    60   Input ~ 0
MOSI
Text GLabel 3700 3250 2    60   Input ~ 0
MISO
Text GLabel 3700 3350 2    60   Input ~ 0
D0
Text GLabel 3700 3450 2    60   Input ~ 0
D1
Wire Wire Line
	3700 3550 4000 3550
Text GLabel 6750 3450 0    60   Input ~ 0
D20
Text GLabel 6750 3350 0    60   Input ~ 0
D21
Text GLabel 6750 3250 0    60   Input ~ 0
D5
Text GLabel 6750 3050 0    60   Input ~ 0
D9
Text GLabel 6750 2950 0    60   Input ~ 0
D10
Text GLabel 6750 2850 0    60   Input ~ 0
D11
Text GLabel 6750 2750 0    60   Input ~ 0
D12
Text GLabel 6750 2650 0    60   Input ~ 0
D13
Text GLabel 6750 2550 0    60   Input ~ 0
VBUS
Text GLabel 6750 2450 0    60   Input ~ 0
EN
Text GLabel 6750 2350 0    60   Input ~ 0
VBAT
Text GLabel 6750 3150 0    60   Input ~ 0
D6
$Comp
L GND #PWR03
U 1 1 5949D0F2
P 4000 3550
F 0 "#PWR03" H 4000 3300 50  0001 C CNN
F 1 "GND" H 4000 3400 50  0000 C CNN
F 2 "" H 4000 3550 50  0001 C CNN
F 3 "" H 4000 3550 50  0001 C CNN
	1    4000 3550
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR04
U 1 1 5949D26C
P 4550 2050
F 0 "#PWR04" H 4550 1900 50  0001 C CNN
F 1 "+3.3V" H 4550 2190 50  0000 C CNN
F 2 "" H 4550 2050 50  0001 C CNN
F 3 "" H 4550 2050 50  0001 C CNN
	1    4550 2050
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR05
U 1 1 5949D292
P 4650 2050
F 0 "#PWR05" H 4650 1800 50  0001 C CNN
F 1 "GND" H 4650 1900 50  0000 C CNN
F 2 "" H 4650 2050 50  0001 C CNN
F 3 "" H 4650 2050 50  0001 C CNN
	1    4650 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 1850 4550 2050
Wire Wire Line
	4550 1950 5500 1950
Wire Wire Line
	5000 1950 5000 1850
Connection ~ 4550 1950
Wire Wire Line
	5500 1950 5500 1850
Connection ~ 5000 1950
Wire Wire Line
	4650 2050 4650 1850
Wire Wire Line
	4650 2050 5600 2050
Wire Wire Line
	5100 2050 5100 1850
Wire Wire Line
	5600 2050 5600 1850
Connection ~ 5100 2050
Text GLabel 5700 1850 3    60   Input ~ 0
A2
Text GLabel 5200 1850 3    60   Input ~ 0
A1
Text GLabel 4750 1850 3    60   Input ~ 0
A0
$Comp
L +3.3V #PWR06
U 1 1 5949D374
P 4450 2450
F 0 "#PWR06" H 4450 2300 50  0001 C CNN
F 1 "+3.3V" H 4450 2590 50  0000 C CNN
F 2 "" H 4450 2450 50  0001 C CNN
F 3 "" H 4450 2450 50  0001 C CNN
	1    4450 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 3300 4850 3300
$Comp
L GND #PWR07
U 1 1 5949D3E8
P 6000 2950
F 0 "#PWR07" H 6000 2700 50  0001 C CNN
F 1 "GND" H 6000 2800 50  0000 C CNN
F 2 "" H 6000 2950 50  0001 C CNN
F 3 "" H 6000 2950 50  0001 C CNN
	1    6000 2950
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR08
U 1 1 5949D414
P 4700 2950
F 0 "#PWR08" H 4700 2700 50  0001 C CNN
F 1 "GND" H 4700 2800 50  0000 C CNN
F 2 "" H 4700 2950 50  0001 C CNN
F 3 "" H 4700 2950 50  0001 C CNN
	1    4700 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 2900 4700 2900
Wire Wire Line
	4700 2900 4700 3000
Wire Wire Line
	4700 3000 4850 3000
Connection ~ 4700 2950
Wire Wire Line
	5850 2900 6000 2900
Wire Wire Line
	6000 2900 6000 3000
Wire Wire Line
	6000 3000 5850 3000
Connection ~ 6000 2950
$Comp
L CONN_02X03 LM1
U 1 1 5949D5A8
P 4450 3850
F 0 "LM1" H 4450 4050 50  0000 C CNN
F 1 "CONN_02X03" H 4450 3650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03_Pitch2.54mm" H 4450 2650 50  0001 C CNN
F 3 "" H 4450 2650 50  0001 C CNN
	1    4450 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X03 RM1
U 1 1 5949D5ED
P 5950 3850
F 0 "RM1" H 5950 4050 50  0000 C CNN
F 1 "CONN_02X03" H 5950 3650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03_Pitch2.54mm" H 5950 2650 50  0001 C CNN
F 3 "" H 5950 2650 50  0001 C CNN
	1    5950 3850
	1    0    0    -1  
$EndComp
Text GLabel 4200 3750 0    60   Input ~ 0
LM-
Text GLabel 4700 3750 2    60   Input ~ 0
LM+
$Comp
L GND #PWR09
U 1 1 5949D733
P 3900 3850
F 0 "#PWR09" H 3900 3600 50  0001 C CNN
F 1 "GND" H 3900 3700 50  0000 C CNN
F 2 "" H 3900 3850 50  0001 C CNN
F 3 "" H 3900 3850 50  0001 C CNN
	1    3900 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	3900 3850 4200 3850
$Comp
L +3.3V #PWR010
U 1 1 5949D785
P 5050 3850
F 0 "#PWR010" H 5050 3700 50  0001 C CNN
F 1 "+3.3V" H 5050 3990 50  0000 C CNN
F 2 "" H 5050 3850 50  0001 C CNN
F 3 "" H 5050 3850 50  0001 C CNN
	1    5050 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 3850 4700 3850
$Comp
L +3.3V #PWR011
U 1 1 5949D7D8
P 6600 3850
F 0 "#PWR011" H 6600 3700 50  0001 C CNN
F 1 "+3.3V" H 6600 3990 50  0000 C CNN
F 2 "" H 6600 3850 50  0001 C CNN
F 3 "" H 6600 3850 50  0001 C CNN
	1    6600 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 3850 6200 3850
$Comp
L GND #PWR012
U 1 1 5949D82C
P 5400 3850
F 0 "#PWR012" H 5400 3600 50  0001 C CNN
F 1 "GND" H 5400 3700 50  0000 C CNN
F 2 "" H 5400 3850 50  0001 C CNN
F 3 "" H 5400 3850 50  0001 C CNN
	1    5400 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 3850 5700 3850
Text GLabel 5700 3750 0    60   Input ~ 0
RM-
Text GLabel 6200 3750 2    60   Input ~ 0
RM+
Text GLabel 6200 3950 2    60   Input ~ 0
D21
Text GLabel 5700 3950 0    60   Input ~ 0
D20
Text GLabel 4200 3950 0    60   Input ~ 0
D0
Text GLabel 4700 3950 2    60   Input ~ 0
D1
Text GLabel 5850 2800 2    60   Input ~ 0
RM+
Text GLabel 5850 3100 2    60   Input ~ 0
RM-
Text GLabel 4850 2800 0    60   Input ~ 0
LM+
Text GLabel 4850 3100 0    60   Input ~ 0
LM-
Text GLabel 4850 2700 0    60   Input ~ 0
D6
Text GLabel 4850 3200 0    60   Input ~ 0
D5
Text GLabel 5850 2700 2    60   Input ~ 0
D13
Text GLabel 5850 3200 2    60   Input ~ 0
D12
Wire Wire Line
	4450 2450 4450 3300
Wire Wire Line
	5850 2600 5850 2400
Wire Wire Line
	5850 2400 4550 2400
Wire Wire Line
	4550 2400 4550 2500
Wire Wire Line
	4550 2500 4450 2500
Connection ~ 4450 2500
Text GLabel 5850 3300 2    60   Input ~ 0
D11
Text GLabel 4850 2600 0    60   Input ~ 0
D10
$EndSCHEMATC
