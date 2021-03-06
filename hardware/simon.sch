EESchema Schematic File Version 4
EELAYER 30 0
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
L power:GND #PWR0101
U 1 1 617FA64B
P 650 2000
F 0 "#PWR0101" H 650 1750 50  0001 C CNN
F 1 "GND" H 655 1827 50  0000 C CNN
F 2 "" H 650 2000 50  0001 C CNN
F 3 "" H 650 2000 50  0001 C CNN
	1    650  2000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW0
U 1 1 617FE5CA
P 950 850
F 0 "SW0" H 950 1135 50  0000 C CNN
F 1 "SW_RED" H 950 1044 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 950 1050 50  0001 C CNN
F 3 "~" H 950 1050 50  0001 C CNN
	1    950  850 
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 618004CA
P 950 1200
F 0 "SW1" H 950 1485 50  0000 C CNN
F 1 "SW_YELLOW" H 950 1394 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 950 1400 50  0001 C CNN
F 3 "~" H 950 1400 50  0001 C CNN
	1    950  1200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 61801321
P 950 1550
F 0 "SW2" H 950 1835 50  0000 C CNN
F 1 "SW_GREEN" H 950 1744 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 950 1750 50  0001 C CNN
F 3 "~" H 950 1750 50  0001 C CNN
	1    950  1550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 61801689
P 950 1900
F 0 "SW3" H 950 2185 50  0000 C CNN
F 1 "SW_BLUE" H 950 2094 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H4.3mm" H 950 2100 50  0001 C CNN
F 3 "~" H 950 2100 50  0001 C CNN
	1    950  1900
	1    0    0    -1  
$EndComp
Text GLabel 1300 850  2    50   Input ~ 0
SWC_RED
Text GLabel 1300 1200 2    50   Input ~ 0
SWC_YLW
Text GLabel 1300 1550 2    50   Input ~ 0
SWC_GRE
Wire Wire Line
	750  850  650  850 
Wire Wire Line
	750  1200 650  1200
Wire Wire Line
	750  1550 650  1550
Wire Wire Line
	650  1900 750  1900
Connection ~ 650  1900
Wire Wire Line
	650  1900 650  2000
Text GLabel 2150 850  0    50   Input ~ 0
LED_RED
Text GLabel 2150 1200 0    50   Input ~ 0
LED_YLW
Text GLabel 2150 1550 0    50   Input ~ 0
LED_GRE
Text GLabel 2150 1900 0    50   Input ~ 0
LED_BLU
$Comp
L Device:R R4
U 1 1 6182D2A7
P 2450 850
F 0 "R4" V 2243 850 50  0000 C CNN
F 1 "56" V 2334 850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2380 850 50  0001 C CNN
F 3 "~" H 2450 850 50  0001 C CNN
	1    2450 850 
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 6182E2EB
P 2450 1200
F 0 "R5" V 2243 1200 50  0000 C CNN
F 1 "58" V 2334 1200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2380 1200 50  0001 C CNN
F 3 "~" H 2450 1200 50  0001 C CNN
	1    2450 1200
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 6182EB3A
P 2450 1550
F 0 "R6" V 2243 1550 50  0000 C CNN
F 1 "51" V 2334 1550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2380 1550 50  0001 C CNN
F 3 "~" H 2450 1550 50  0001 C CNN
	1    2450 1550
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 6182F140
P 2450 1900
F 0 "R7" V 2243 1900 50  0000 C CNN
F 1 "19" V 2334 1900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2380 1900 50  0001 C CNN
F 3 "~" H 2450 1900 50  0001 C CNN
	1    2450 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 850  2300 850 
Wire Wire Line
	2300 1200 2150 1200
Wire Wire Line
	2300 1550 2150 1550
Wire Wire Line
	2150 1900 2300 1900
$Comp
L power:GND #PWR0103
U 1 1 61831AB4
P 3100 2000
F 0 "#PWR0103" H 3100 1750 50  0001 C CNN
F 1 "GND" H 3105 1827 50  0000 C CNN
F 2 "" H 3100 2000 50  0001 C CNN
F 3 "" H 3100 2000 50  0001 C CNN
	1    3100 2000
	-1   0    0    -1  
$EndComp
$Comp
L Device:LED D0
U 1 1 6183A3CC
P 2850 850
F 0 "D0" H 2843 595 50  0000 C CNN
F 1 "LED_RED" H 2843 686 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2850 850 50  0001 C CNN
F 3 "~" H 2850 850 50  0001 C CNN
	1    2850 850 
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D1
U 1 1 6183CBFB
P 2850 1200
F 0 "D1" H 2843 945 50  0000 C CNN
F 1 "LED_YELLOW" H 2843 1036 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2850 1200 50  0001 C CNN
F 3 "~" H 2850 1200 50  0001 C CNN
	1    2850 1200
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D2
U 1 1 6183D788
P 2850 1550
F 0 "D2" H 2843 1295 50  0000 C CNN
F 1 "LED_GREEN" H 2843 1386 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2850 1550 50  0001 C CNN
F 3 "~" H 2850 1550 50  0001 C CNN
	1    2850 1550
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D3
U 1 1 6183E4E9
P 2850 1900
F 0 "D3" H 2843 1645 50  0000 C CNN
F 1 "LED_BLUE" H 2843 1736 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2850 1900 50  0001 C CNN
F 3 "~" H 2850 1900 50  0001 C CNN
	1    2850 1900
	-1   0    0    1   
$EndComp
Wire Wire Line
	2700 1900 2600 1900
Wire Wire Line
	2600 1550 2700 1550
Wire Wire Line
	2700 1200 2600 1200
Wire Wire Line
	2600 850  2700 850 
Wire Wire Line
	3100 2000 3100 1900
Wire Wire Line
	3100 850  3000 850 
Wire Wire Line
	3000 1200 3100 1200
Connection ~ 3100 1200
Wire Wire Line
	3100 1200 3100 850 
Wire Wire Line
	3100 1550 3000 1550
Connection ~ 3100 1550
Wire Wire Line
	3100 1550 3100 1200
Wire Wire Line
	3000 1900 3100 1900
Connection ~ 3100 1900
Wire Wire Line
	3100 1900 3100 1550
Text GLabel 1300 1900 2    50   Input ~ 0
SWC_BLU
Wire Wire Line
	650  1200 650  1550
Connection ~ 650  1550
Wire Wire Line
	650  1550 650  1900
Wire Wire Line
	650  850  650  1200
Connection ~ 650  1200
$Comp
L Device:Speaker_Crystal LS0
U 1 1 618756C2
P 3150 2700
F 0 "LS0" H 3325 2696 50  0000 L CNN
F 1 "BUZZER" H 3325 2605 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" H 3115 2650 50  0001 C CNN
F 3 "~" H 3115 2650 50  0001 C CNN
	1    3150 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 61876E39
P 2700 2700
F 0 "R8" V 2493 2700 50  0000 C CNN
F 1 "110" V 2584 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2630 2700 50  0001 C CNN
F 3 "~" H 2700 2700 50  0001 C CNN
	1    2700 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 2700 2950 2700
Text GLabel 2450 2800 3    50   Input ~ 0
BUZZ
$Comp
L power:GND #PWR0104
U 1 1 6187DA46
P 2850 2900
F 0 "#PWR0104" H 2850 2650 50  0001 C CNN
F 1 "GND" H 2855 2727 50  0000 C CNN
F 2 "" H 2850 2900 50  0001 C CNN
F 3 "" H 2850 2900 50  0001 C CNN
	1    2850 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 2900 2850 2800
Wire Wire Line
	2850 2800 2950 2800
Wire Wire Line
	2550 2700 2450 2700
Wire Wire Line
	2450 2700 2450 2800
Text GLabel 900  2950 0    50   Output ~ 0
LED_BLU
Text GLabel 900  3050 0    50   Output ~ 0
SWC_BLU
Text GLabel 900  3150 0    50   Output ~ 0
LED_RED
Text GLabel 900  3250 0    50   Output ~ 0
SWC_RED
Text GLabel 900  3350 0    50   Output ~ 0
LED_YLW
Text GLabel 900  3450 0    50   Output ~ 0
SWC_YLW
Text GLabel 900  3550 0    50   Output ~ 0
LED_GRE
Text GLabel 900  3650 0    50   Output ~ 0
SWC_GRE
Text GLabel 2100 3550 2    50   Output ~ 0
BUZZ
Wire Wire Line
	2100 3550 2000 3550
$Comp
L MCU_Module:Arduino_UNO_R3 A0
U 1 1 618123D3
P 1500 3550
F 0 "A0" H 1500 4731 50  0001 C CNN
F 1 "Arduino_UNO_R3" H 1500 4639 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 1500 3550 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 1500 3550 50  0001 C CNN
	1    1500 3550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0105
U 1 1 61834727
P 1600 2350
F 0 "#PWR0105" H 1600 2200 50  0001 C CNN
F 1 "VCC" H 1615 2523 50  0000 C CNN
F 2 "" H 1600 2350 50  0001 C CNN
F 3 "" H 1600 2350 50  0001 C CNN
	1    1600 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2350 1600 2550
$Comp
L power:GND #PWR0106
U 1 1 61836617
P 1700 4750
F 0 "#PWR0106" H 1700 4500 50  0001 C CNN
F 1 "GND" H 1705 4577 50  0000 C CNN
F 2 "" H 1700 4750 50  0001 C CNN
F 3 "" H 1700 4750 50  0001 C CNN
	1    1700 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 4750 1600 4650
$Comp
L power:GND #PWR0107
U 1 1 6180680E
P 1500 4750
F 0 "#PWR0107" H 1500 4500 50  0001 C CNN
F 1 "GND" H 1505 4577 50  0000 C CNN
F 2 "" H 1500 4750 50  0001 C CNN
F 3 "" H 1500 4750 50  0001 C CNN
	1    1500 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 4750 1500 4650
$Comp
L power:GND #PWR0108
U 1 1 61807C2A
P 1300 4750
F 0 "#PWR0108" H 1300 4500 50  0001 C CNN
F 1 "GND" H 1305 4577 50  0000 C CNN
F 2 "" H 1300 4750 50  0001 C CNN
F 3 "" H 1300 4750 50  0001 C CNN
	1    1300 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 4750 1400 4650
Wire Wire Line
	1400 4750 1300 4750
Wire Wire Line
	1600 4750 1700 4750
Wire Wire Line
	1150 850  1300 850 
Wire Wire Line
	1150 1200 1300 1200
Wire Wire Line
	1150 1550 1300 1550
Wire Wire Line
	1150 1900 1300 1900
Wire Wire Line
	900  3650 1000 3650
Wire Wire Line
	1000 3550 900  3550
Wire Wire Line
	900  3450 1000 3450
Wire Wire Line
	1000 3350 900  3350
Wire Wire Line
	900  3250 1000 3250
Wire Wire Line
	1000 3150 900  3150
Wire Wire Line
	900  3050 1000 3050
Wire Wire Line
	1000 2950 900  2950
$EndSCHEMATC
