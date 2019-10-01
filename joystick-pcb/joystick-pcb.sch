EESchema Schematic File Version 4
LIBS:rover-pcb-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Rover Joystick"
Date "2019-10-01"
Rev "1"
Comp "Emil Jaregran"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U3
U 1 1 5D942B3C
P 7300 3100
F 0 "U3" H 7800 1500 50  0000 C CNN
F 1 "ATmega328P-AU" H 7800 1400 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 7300 3100 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 7300 3100 50  0001 C CNN
	1    7300 3100
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR025
U 1 1 5D94623E
P 7300 1050
F 0 "#PWR025" H 7300 900 50  0001 C CNN
F 1 "+5V" H 7315 1223 50  0000 C CNN
F 2 "" H 7300 1050 50  0001 C CNN
F 3 "" H 7300 1050 50  0001 C CNN
	1    7300 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR026
U 1 1 5D947C37
P 7300 4700
F 0 "#PWR026" H 7300 4450 50  0001 C CNN
F 1 "GND" H 7305 4527 50  0000 C CNN
F 2 "" H 7300 4700 50  0001 C CNN
F 3 "" H 7300 4700 50  0001 C CNN
	1    7300 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 4700 7300 4600
Wire Wire Line
	7300 1050 7300 1150
$Comp
L Device:R_Small R4
U 1 1 5D949348
P 6350 5800
F 0 "R4" H 6250 5775 50  0000 C CNN
F 1 "10k" H 6225 5850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6350 5800 50  0001 C CNN
F 3 "~" H 6350 5800 50  0001 C CNN
	1    6350 5800
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR020
U 1 1 5D94A0DB
P 6350 5650
F 0 "#PWR020" H 6350 5500 50  0001 C CNN
F 1 "+5V" H 6365 5823 50  0000 C CNN
F 2 "" H 6350 5650 50  0001 C CNN
F 3 "" H 6350 5650 50  0001 C CNN
	1    6350 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C10
U 1 1 5D94C6DA
P 7100 1300
F 0 "C10" H 6850 1350 50  0000 L CNN
F 1 "100nF" H 6750 1250 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7100 1300 50  0001 C CNN
F 3 "~" H 7100 1300 50  0001 C CNN
	1    7100 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR023
U 1 1 5D94F51F
P 7100 1450
F 0 "#PWR023" H 7100 1200 50  0001 C CNN
F 1 "GND" H 7105 1277 50  0000 C CNN
F 2 "" H 7100 1450 50  0001 C CNN
F 3 "" H 7100 1450 50  0001 C CNN
	1    7100 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 1200 7100 1150
Wire Wire Line
	7100 1150 7300 1150
Connection ~ 7300 1150
Wire Wire Line
	7300 1150 7300 1600
$Comp
L Device:C_Small C8
U 1 1 5D951338
P 6500 2050
F 0 "C8" H 6300 2100 50  0000 L CNN
F 1 "100nF" H 6150 2000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6500 2050 50  0001 C CNN
F 3 "~" H 6500 2050 50  0001 C CNN
	1    6500 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5D9519E4
P 6500 2150
F 0 "#PWR021" H 6500 1900 50  0001 C CNN
F 1 "GND" H 6505 1977 50  0000 C CNN
F 2 "" H 6500 2150 50  0001 C CNN
F 3 "" H 6500 2150 50  0001 C CNN
	1    6500 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 1950 6500 1900
Wire Wire Line
	6500 1900 6700 1900
NoConn ~ 6700 2100
NoConn ~ 6700 2200
Wire Wire Line
	7100 1450 7100 1400
$Comp
L Device:Crystal_GND24_Small Y1
U 1 1 5D97661E
P 8350 5800
F 0 "Y1" H 8400 6100 50  0000 R CNN
F 1 "16 MHz" H 8500 6000 50  0000 R CNN
F 2 "Crystal:Crystal_SMD_EuroQuartz_MJ-4Pin_5.0x3.2mm_HandSoldering" H 8350 5800 50  0001 C CNN
F 3 "~" H 8350 5800 50  0001 C CNN
	1    8350 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C13
U 1 1 5D98756F
P 8650 6050
F 0 "C13" H 8400 6100 50  0000 L CNN
F 1 "12pF" H 8375 6000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8650 6050 50  0001 C CNN
F 3 "~" H 8650 6050 50  0001 C CNN
	1    8650 6050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C12
U 1 1 5D98794E
P 8150 6050
F 0 "C12" H 7900 6100 50  0000 L CNN
F 1 "12pF" H 7850 6000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8150 6050 50  0001 C CNN
F 3 "~" H 8150 6050 50  0001 C CNN
	1    8150 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 6150 8150 6300
Wire Wire Line
	8650 6300 8650 6150
$Comp
L power:GND #PWR029
U 1 1 5D99657C
P 8500 6350
F 0 "#PWR029" H 8500 6100 50  0001 C CNN
F 1 "GND" H 8650 6275 50  0000 C CNN
F 2 "" H 8500 6350 50  0001 C CNN
F 3 "" H 8500 6350 50  0001 C CNN
	1    8500 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 3400 7900 3400
Connection ~ 8650 6300
Wire Wire Line
	8150 6300 8350 6300
$Comp
L Regulator_Linear:MC78M05_TO252 U2
U 1 1 5D9A67D9
P 2000 1300
F 0 "U2" H 2000 1542 50  0000 C CNN
F 1 "MC78M05_TO252" H 2000 1451 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 2000 1525 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM78M05.pdf" H 2000 1250 50  0001 C CNN
	1    2000 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5D9A7A58
P 2250 1750
F 0 "#PWR010" H 2250 1500 50  0001 C CNN
F 1 "GND" H 2250 1600 50  0000 C CNN
F 2 "" H 2250 1750 50  0001 C CNN
F 3 "" H 2250 1750 50  0001 C CNN
	1    2250 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR013
U 1 1 5D9AA537
P 2750 1150
F 0 "#PWR013" H 2750 1000 50  0001 C CNN
F 1 "+5V" H 2750 1300 50  0000 C CNN
F 2 "" H 2750 1150 50  0001 C CNN
F 3 "" H 2750 1150 50  0001 C CNN
	1    2750 1150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5D9AB5D6
P 800 1400
F 0 "J1" H 800 1500 50  0000 C CNN
F 1 "BATT IN" H 750 1600 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-2-5.08_1x02_P5.08mm_Horizontal" H 800 1400 50  0001 C CNN
F 3 "~" H 800 1400 50  0001 C CNN
	1    800  1400
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5D9B012E
P 1350 1750
F 0 "#PWR06" H 1350 1500 50  0001 C CNN
F 1 "GND" H 1355 1577 50  0000 C CNN
F 2 "" H 1350 1750 50  0001 C CNN
F 3 "" H 1350 1750 50  0001 C CNN
	1    1350 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1400 1050 1400
$Comp
L Device:CP_Small C2
U 1 1 5D9B1786
P 1350 1450
F 0 "C2" H 1438 1496 50  0000 L CNN
F 1 "1μF" H 1438 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1350 1450 50  0001 C CNN
F 3 "~" H 1350 1450 50  0001 C CNN
	1    1350 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1350 1350 1300
Wire Wire Line
	1350 1300 1150 1300
Wire Wire Line
	1050 1600 1050 1400
Wire Wire Line
	1350 1600 1350 1750
Connection ~ 1350 1600
Wire Wire Line
	1350 1600 1150 1600
Wire Wire Line
	1700 1300 1350 1300
Connection ~ 1350 1300
Wire Wire Line
	1350 1600 1350 1550
$Comp
L Device:C_Small C4
U 1 1 5D9D790A
P 2500 1450
F 0 "C4" H 2600 1500 50  0000 L CNN
F 1 "100nF" H 2600 1400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2500 1450 50  0001 C CNN
F 3 "~" H 2500 1450 50  0001 C CNN
	1    2500 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1300 2500 1300
Wire Wire Line
	2500 1300 2500 1350
Wire Wire Line
	2000 1700 2000 1600
Wire Wire Line
	2500 1700 2500 1550
Wire Wire Line
	2500 1300 2750 1300
Wire Wire Line
	2750 1300 2750 1150
Connection ~ 2500 1300
$Comp
L Regulator_Linear:L78L33_SOT89 U1
U 1 1 5D9F1E37
P 1650 3000
F 0 "U1" H 1650 3242 50  0000 C CNN
F 1 "L78L33_SOT89" H 1650 3151 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-89-3" H 1650 3200 50  0001 C CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/15/55/e5/aa/23/5b/43/fd/CD00000446.pdf/files/CD00000446.pdf/jcr:content/translations/en.CD00000446.pdf" H 1650 2950 50  0001 C CNN
	1    1650 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1150 1350 1300
$Comp
L power:GND #PWR07
U 1 1 5D9F6E15
P 1900 3450
F 0 "#PWR07" H 1900 3200 50  0001 C CNN
F 1 "GND" H 1905 3277 50  0000 C CNN
F 2 "" H 1900 3450 50  0001 C CNN
F 3 "" H 1900 3450 50  0001 C CNN
	1    1900 3450
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR011
U 1 1 5D9F7477
P 2450 2850
F 0 "#PWR011" H 2450 2700 50  0001 C CNN
F 1 "+3.3V" H 2465 3023 50  0000 C CNN
F 2 "" H 2450 2850 50  0001 C CNN
F 3 "" H 2450 2850 50  0001 C CNN
	1    2450 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5D9F87C8
P 2200 3200
F 0 "C3" H 2300 3250 50  0000 L CNN
F 1 "100nF" H 2300 3150 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2200 3200 50  0001 C CNN
F 3 "~" H 2200 3200 50  0001 C CNN
	1    2200 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 3000 2200 3000
Wire Wire Line
	2200 3000 2200 3100
Wire Wire Line
	2200 3000 2450 3000
Wire Wire Line
	2450 3000 2450 2850
Connection ~ 2200 3000
Wire Wire Line
	1650 3300 1650 3400
Wire Wire Line
	1650 3400 1900 3400
Wire Wire Line
	1900 3400 1900 3450
Wire Wire Line
	1900 3400 2200 3400
Wire Wire Line
	2200 3400 2200 3300
Connection ~ 1900 3400
Wire Wire Line
	1350 3000 1250 3000
$Comp
L Device:CP_Small C1
U 1 1 5DA1C71F
P 1250 3200
F 0 "C1" H 1050 3250 50  0000 L CNN
F 1 "0.33μF" H 900 3150 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1250 3200 50  0001 C CNN
F 3 "~" H 1250 3200 50  0001 C CNN
	1    1250 3200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5DA1F890
P 1250 3450
F 0 "#PWR04" H 1250 3200 50  0001 C CNN
F 1 "GND" H 1255 3277 50  0000 C CNN
F 2 "" H 1250 3450 50  0001 C CNN
F 3 "" H 1250 3450 50  0001 C CNN
	1    1250 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 3450 1250 3300
Wire Wire Line
	1250 3000 1250 3100
Wire Wire Line
	1250 3000 1050 3000
Wire Wire Line
	1050 3000 1050 2850
Connection ~ 1250 3000
$Comp
L power:GND #PWR09
U 1 1 5DA415B1
P 2000 5550
F 0 "#PWR09" H 2000 5300 50  0001 C CNN
F 1 "GND" H 2150 5475 50  0000 C CNN
F 2 "" H 2000 5550 50  0001 C CNN
F 3 "" H 2000 5550 50  0001 C CNN
	1    2000 5550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR08
U 1 1 5DA42BA7
P 2000 4550
F 0 "#PWR08" H 2000 4400 50  0001 C CNN
F 1 "+5V" H 2015 4723 50  0000 C CNN
F 2 "" H 2000 4550 50  0001 C CNN
F 3 "" H 2000 4550 50  0001 C CNN
	1    2000 4550
	1    0    0    -1  
$EndComp
Text Label 8200 3400 0    50   ~ 0
~RST
Text Label 1300 5200 2    50   ~ 0
~RST
Wire Wire Line
	7900 2400 8200 2400
Text Label 8200 2400 0    50   ~ 0
SCK
Text Label 1300 5100 2    50   ~ 0
SCK
Wire Wire Line
	7900 2300 8200 2300
Text Label 8200 2300 0    50   ~ 0
MISO
Text Label 1300 4900 2    50   ~ 0
MISO
Wire Wire Line
	7900 2200 8200 2200
Text Label 8200 2200 0    50   ~ 0
MOSI
Text Label 1300 5000 2    50   ~ 0
MOSI
Wire Wire Line
	7900 3700 8200 3700
Text Label 8200 3700 0    50   ~ 0
TXD
Wire Wire Line
	7900 3600 8200 3600
Text Label 8200 3600 0    50   ~ 0
RXD
$Comp
L Connector:AVR-ISP-6 J2
U 1 1 5DA38619
P 1900 5100
F 0 "J2" H 1620 5196 50  0000 R CNN
F 1 "AVR-ISP-6" H 1620 5105 50  0000 R CNN
F 2 "Connector_IDC:IDC-Header_2x03_P2.54mm_Vertical" V 1650 5150 50  0001 C CNN
F 3 " ~" H 625 4550 50  0001 C CNN
	1    1900 5100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2000 4550 2000 4600
Wire Wire Line
	2000 5550 2000 5500
Wire Wire Line
	1500 4900 1300 4900
Wire Wire Line
	1500 5000 1300 5000
Wire Wire Line
	1500 5100 1300 5100
Wire Wire Line
	1500 5200 1300 5200
$Comp
L power:+5V #PWR031
U 1 1 5DB18D67
P 9600 1050
F 0 "#PWR031" H 9600 900 50  0001 C CNN
F 1 "+5V" H 9615 1223 50  0000 C CNN
F 2 "" H 9600 1050 50  0001 C CNN
F 3 "" H 9600 1050 50  0001 C CNN
	1    9600 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 1050 9600 1200
Text Label 9650 1400 2    50   ~ 0
BT_TX
Text Label 9650 1500 2    50   ~ 0
BT_RX
$Comp
L power:GND #PWR030
U 1 1 5DB27A90
P 9350 1650
F 0 "#PWR030" H 9350 1400 50  0001 C CNN
F 1 "GND" H 9500 1575 50  0000 C CNN
F 2 "" H 9350 1650 50  0001 C CNN
F 3 "" H 9350 1650 50  0001 C CNN
	1    9350 1650
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:BSS138 Q1
U 1 1 5DB74BA1
P 9800 3350
F 0 "Q1" H 10006 3396 50  0000 L CNN
F 1 "BSS138" H 10006 3305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 10000 3275 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 9800 3350 50  0001 L CNN
	1    9800 3350
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Small R8
U 1 1 5DB83BA2
P 10150 3550
F 0 "R8" H 10025 3525 50  0000 C CNN
F 1 "10k" H 10000 3600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10150 3550 50  0001 C CNN
F 3 "~" H 10150 3550 50  0001 C CNN
	1    10150 3550
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR034
U 1 1 5DB8717F
P 10150 3250
F 0 "#PWR034" H 10150 3100 50  0001 C CNN
F 1 "+3.3V" H 10165 3423 50  0000 C CNN
F 2 "" H 10150 3250 50  0001 C CNN
F 3 "" H 10150 3250 50  0001 C CNN
	1    10150 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R6
U 1 1 5DBB0981
P 9700 2950
F 0 "R6" H 9575 2925 50  0000 C CNN
F 1 "10k" H 9550 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9700 2950 50  0001 C CNN
F 3 "~" H 9700 2950 50  0001 C CNN
	1    9700 2950
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR032
U 1 1 5DBBF102
P 9700 2800
F 0 "#PWR032" H 9700 2650 50  0001 C CNN
F 1 "+5V" H 9715 2973 50  0000 C CNN
F 2 "" H 9700 2800 50  0001 C CNN
F 3 "" H 9700 2800 50  0001 C CNN
	1    9700 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 3350 10150 3350
Wire Wire Line
	10150 3350 10150 3250
Wire Wire Line
	10150 3650 10150 3800
Wire Wire Line
	10150 3800 9700 3800
Wire Wire Line
	9700 3800 9700 3550
Wire Wire Line
	10150 3450 10150 3350
Connection ~ 10150 3350
Wire Wire Line
	10150 3800 10450 3800
Connection ~ 10150 3800
Wire Wire Line
	9700 2800 9700 2850
Wire Wire Line
	9700 3050 9700 3100
Wire Wire Line
	9700 3100 9400 3100
Connection ~ 9700 3100
Wire Wire Line
	9700 3100 9700 3150
$Comp
L Transistor_FET:BSS138 Q2
U 1 1 5DC303EC
P 9800 4850
F 0 "Q2" H 10006 4896 50  0000 L CNN
F 1 "BSS138" H 10006 4805 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 10000 4775 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 9800 4850 50  0001 L CNN
	1    9800 4850
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Small R9
U 1 1 5DC303F6
P 10150 5050
F 0 "R9" H 10025 5025 50  0000 C CNN
F 1 "10k" H 10000 5100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 10150 5050 50  0001 C CNN
F 3 "~" H 10150 5050 50  0001 C CNN
	1    10150 5050
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR035
U 1 1 5DC30400
P 10150 4750
F 0 "#PWR035" H 10150 4600 50  0001 C CNN
F 1 "+3.3V" H 10165 4923 50  0000 C CNN
F 2 "" H 10150 4750 50  0001 C CNN
F 3 "" H 10150 4750 50  0001 C CNN
	1    10150 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R7
U 1 1 5DC3040A
P 9700 4450
F 0 "R7" H 9600 4400 50  0000 C CNN
F 1 "10k" H 9575 4475 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9700 4450 50  0001 C CNN
F 3 "~" H 9700 4450 50  0001 C CNN
	1    9700 4450
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR033
U 1 1 5DC30414
P 9700 4300
F 0 "#PWR033" H 9700 4150 50  0001 C CNN
F 1 "+5V" H 9715 4473 50  0000 C CNN
F 2 "" H 9700 4300 50  0001 C CNN
F 3 "" H 9700 4300 50  0001 C CNN
	1    9700 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 4850 10150 4850
Wire Wire Line
	10150 4850 10150 4750
Wire Wire Line
	10150 5150 10150 5300
Wire Wire Line
	10150 5300 9700 5300
Wire Wire Line
	9700 5300 9700 5050
Wire Wire Line
	10150 4950 10150 4850
Connection ~ 10150 4850
Wire Wire Line
	10150 5300 10450 5300
Connection ~ 10150 5300
Wire Wire Line
	9700 4300 9700 4350
Wire Wire Line
	9700 4550 9700 4600
Wire Wire Line
	9700 4600 9400 4600
Connection ~ 9700 4600
Wire Wire Line
	9700 4600 9700 4650
Text Label 10450 3800 0    50   ~ 0
BT_TX
Text Label 10450 5300 0    50   ~ 0
BT_RX
Text Label 9400 3100 2    50   ~ 0
RXD
Text Label 9400 4600 2    50   ~ 0
TXD
Wire Notes Line
	9000 2300 10900 2300
Wire Notes Line
	10900 2300 10900 5400
Wire Notes Line
	10900 5400 9000 5400
Wire Notes Line
	9000 5400 9000 2300
Text Notes 9400 2500 0    79   ~ 0
UART level shifters
Wire Notes Line
	9000 1950 10900 1950
Wire Notes Line
	10900 1950 10900 600 
Wire Notes Line
	10900 600  9000 600 
Wire Notes Line
	9000 600  9000 1950
Text Notes 9400 800  0    79   ~ 0
Bluetooth module
Text Notes 1250 800  0    79   ~ 0
+5V power supply
Wire Notes Line
	600  600  2950 600 
Wire Notes Line
	2950 600  2950 2050
Wire Notes Line
	2950 2050 600  2050
Wire Notes Line
	600  2050 600  600 
Text Notes 1200 2550 0    79   ~ 0
+3.3V power supply
Wire Notes Line
	600  2350 2950 2350
Wire Notes Line
	2950 2350 2950 3750
Wire Notes Line
	2950 3750 600  3750
Wire Notes Line
	600  3750 600  2350
Text Notes 1100 4250 0    79   ~ 0
Programming interface
Wire Notes Line
	2950 4050 600  4050
Wire Notes Line
	600  4050 600  5750
Wire Notes Line
	600  5750 2950 5750
Wire Notes Line
	2950 5750 2950 4050
$Comp
L Connector:TestPoint TP1
U 1 1 5DDF739A
P 750 6750
F 0 "TP1" H 800 7000 50  0000 R CNN
F 1 "+3.3V" H 800 7100 50  0000 R CNN
F 2 "TestPoint:TestPoint_THTPad_D2.0mm_Drill1.0mm" H 950 6750 50  0001 C CNN
F 3 "~" H 950 6750 50  0001 C CNN
	1    750  6750
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR01
U 1 1 5DDFF320
P 750 6650
F 0 "#PWR01" H 750 6500 50  0001 C CNN
F 1 "+3.3V" H 765 6823 50  0000 C CNN
F 2 "" H 750 6650 50  0001 C CNN
F 3 "" H 750 6650 50  0001 C CNN
	1    750  6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	750  6650 750  6750
$Comp
L Connector:TestPoint TP2
U 1 1 5DE03207
P 1200 6750
F 0 "TP2" H 1250 7000 50  0000 R CNN
F 1 "+5V" H 1250 7100 50  0000 R CNN
F 2 "TestPoint:TestPoint_THTPad_D2.0mm_Drill1.0mm" H 1400 6750 50  0001 C CNN
F 3 "~" H 1400 6750 50  0001 C CNN
	1    1200 6750
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 5DE060FD
P 1200 6650
F 0 "#PWR03" H 1200 6500 50  0001 C CNN
F 1 "+5V" H 1215 6823 50  0000 C CNN
F 2 "" H 1200 6650 50  0001 C CNN
F 3 "" H 1200 6650 50  0001 C CNN
	1    1200 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 6650 1200 6750
Text Notes 1500 6250 0    79   ~ 0
Test points
$Comp
L Connector:TestPoint TP3
U 1 1 5DE41F0E
P 1650 6750
F 0 "TP3" H 1700 7000 50  0000 R CNN
F 1 "RXD" H 1700 7100 50  0000 R CNN
F 2 "TestPoint:TestPoint_THTPad_D2.0mm_Drill1.0mm" H 1850 6750 50  0001 C CNN
F 3 "~" H 1850 6750 50  0001 C CNN
	1    1650 6750
	-1   0    0    1   
$EndComp
$Comp
L Connector:TestPoint TP4
U 1 1 5DE423A1
P 2100 6750
F 0 "TP4" H 2150 7000 50  0000 R CNN
F 1 "TXD" H 2150 7100 50  0000 R CNN
F 2 "TestPoint:TestPoint_THTPad_D2.0mm_Drill1.0mm" H 2300 6750 50  0001 C CNN
F 3 "~" H 2300 6750 50  0001 C CNN
	1    2100 6750
	-1   0    0    1   
$EndComp
Wire Wire Line
	1650 6500 1700 6500
Wire Wire Line
	2100 6500 2150 6500
Text Label 2150 6500 0    50   ~ 0
TXD
Text Label 1700 6500 0    50   ~ 0
RXD
Wire Notes Line
	600  6050 2950 6050
Wire Notes Line
	2950 6050 2950 7300
Wire Notes Line
	2950 7300 600  7300
Wire Notes Line
	600  7300 600  6050
$Comp
L Device:R_Small R5
U 1 1 5DA800D5
P 7250 5650
F 0 "R5" H 7100 5600 50  0000 C CNN
F 1 "330R" H 7050 5700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7250 5650 50  0001 C CNN
F 3 "~" H 7250 5650 50  0001 C CNN
	1    7250 5650
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D1
U 1 1 5DA7F6F3
P 7250 5950
F 0 "D1" V 7289 5833 50  0000 R CNN
F 1 "LED" V 7198 5833 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7250 5950 50  0001 C CNN
F 3 "~" H 7250 5950 50  0001 C CNN
	1    7250 5950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7900 2500 8200 2500
Wire Wire Line
	7900 2600 8200 2600
Text Label 8200 2500 0    50   ~ 0
XTAL1
Text Label 8200 2600 0    50   ~ 0
XTAL2
Wire Wire Line
	8250 5800 8150 5800
Wire Wire Line
	8150 5800 8150 5950
Wire Wire Line
	8650 5800 8650 5950
Wire Wire Line
	8350 5900 8350 6300
Connection ~ 8350 6300
Wire Wire Line
	8350 6300 8500 6300
Wire Wire Line
	8350 5650 8800 5650
Wire Wire Line
	8800 5650 8800 6300
Wire Wire Line
	8800 6300 8650 6300
Wire Wire Line
	8500 6350 8500 6300
Connection ~ 8500 6300
Wire Wire Line
	8500 6300 8650 6300
Text Notes 8150 5250 0    79   ~ 0
Crystal
Wire Notes Line
	7800 5100 8900 5100
Wire Notes Line
	8900 5100 8900 6500
Wire Notes Line
	8900 6500 7800 6500
Wire Notes Line
	7800 6500 7800 5100
Text Notes 7050 750  0    79   ~ 0
ATMega 328P
Wire Notes Line
	6100 600  8750 600 
Wire Notes Line
	8750 600  8750 5000
Wire Notes Line
	8750 5000 6100 5000
Wire Notes Line
	6100 5000 6100 600 
Text Notes 6950 5250 0    79   ~ 0
Status LED
Wire Notes Line
	6850 5100 7700 5100
Wire Notes Line
	7700 5100 7700 6400
Wire Notes Line
	7700 6400 6850 6400
Wire Notes Line
	6850 6400 6850 5100
Text Label 8200 2000 0    50   ~ 0
LED_1
Text Label 7350 6300 0    50   ~ 0
LED_1
NoConn ~ 7900 3200
NoConn ~ 7900 3300
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5EB2BB26
P 1150 1150
F 0 "#FLG01" H 1150 1225 50  0001 C CNN
F 1 "PWR_FLAG" H 950 1300 50  0000 C CNN
F 2 "" H 1150 1150 50  0001 C CNN
F 3 "~" H 1150 1150 50  0001 C CNN
	1    1150 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 1150 1150 1300
Connection ~ 1150 1300
Wire Wire Line
	1150 1300 1000 1300
Text Label 8600 5500 0    50   ~ 0
XTAL2
Wire Wire Line
	2000 1700 2250 1700
Wire Wire Line
	2250 1750 2250 1700
Connection ~ 2250 1700
Wire Wire Line
	2250 1700 2500 1700
Wire Wire Line
	8350 5700 8350 5650
$Comp
L Connector:TestPoint TP5
U 1 1 5ECEB37D
P 2550 6700
F 0 "TP5" H 2600 6950 50  0000 R CNN
F 1 "GND" H 2800 7050 50  0000 R CNN
F 2 "TestPoint:TestPoint_THTPad_D2.0mm_Drill1.0mm" H 2750 6700 50  0001 C CNN
F 3 "~" H 2750 6700 50  0001 C CNN
	1    2550 6700
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C9
U 1 1 5EDCD275
P 6625 1300
F 0 "C9" H 6425 1350 50  0000 L CNN
F 1 "10μF" H 6325 1250 50  0000 L CNN
F 2 "Capacitor_SMD:C_1210_3225Metric_Pad1.42x2.65mm_HandSolder" H 6625 1300 50  0001 C CNN
F 3 "~" H 6625 1300 50  0001 C CNN
	1    6625 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5EDEE50F
P 6625 1450
F 0 "#PWR022" H 6625 1200 50  0001 C CNN
F 1 "GND" H 6630 1277 50  0000 C CNN
F 2 "" H 6625 1450 50  0001 C CNN
F 3 "" H 6625 1450 50  0001 C CNN
	1    6625 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6625 1400 6625 1450
$Comp
L power:+5V #PWR024
U 1 1 5EE1AB9A
P 7250 5500
F 0 "#PWR024" H 7250 5350 50  0001 C CNN
F 1 "+5V" H 7265 5673 50  0000 C CNN
F 2 "" H 7250 5500 50  0001 C CNN
F 3 "" H 7250 5500 50  0001 C CNN
	1    7250 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 5500 7250 5550
Wire Wire Line
	7250 5750 7250 5800
Wire Wire Line
	7250 6300 7350 6300
Wire Wire Line
	7250 6100 7250 6300
Wire Wire Line
	8450 5800 8550 5800
Wire Wire Line
	8550 5800 8550 5500
Wire Wire Line
	8550 5500 8600 5500
Connection ~ 8550 5800
Wire Wire Line
	8550 5800 8650 5800
Text Label 8100 5500 2    50   ~ 0
XTAL1
Wire Wire Line
	8100 5500 8150 5500
Wire Wire Line
	8150 5500 8150 5800
Connection ~ 8150 5800
Wire Wire Line
	1650 6750 1650 6500
Wire Wire Line
	2100 6750 2100 6500
Text Notes 6600 5250 2    79   ~ 0
Reset
Wire Wire Line
	6350 5650 6350 5700
Wire Wire Line
	6350 5900 6350 6100
Wire Wire Line
	6350 6100 6450 6100
Text Label 6450 6100 0    50   ~ 0
~RST
Wire Notes Line
	6750 5100 6100 5100
Wire Notes Line
	6100 5100 6100 6400
Wire Notes Line
	6100 6400 6750 6400
Wire Notes Line
	6750 6400 6750 5100
Wire Wire Line
	2550 6800 2550 6700
$Comp
L power:GND #PWR012
U 1 1 5ED1A379
P 2550 6800
F 0 "#PWR012" H 2550 6550 50  0001 C CNN
F 1 "GND" H 2550 6600 50  0000 C CNN
F 2 "" H 2550 6800 50  0001 C CNN
F 3 "" H 2550 6800 50  0001 C CNN
	1    2550 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2000 8200 2000
NoConn ~ 7900 2100
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5F326078
P 1150 1750
F 0 "#FLG02" H 1150 1825 50  0001 C CNN
F 1 "PWR_FLAG" H 1350 1925 50  0000 C CNN
F 2 "" H 1150 1750 50  0001 C CNN
F 3 "~" H 1150 1750 50  0001 C CNN
	1    1150 1750
	-1   0    0    1   
$EndComp
Wire Wire Line
	1150 1750 1150 1600
Connection ~ 1150 1600
Wire Wire Line
	1150 1600 1050 1600
$Comp
L Connector:Conn_01x06_Male J6
U 1 1 5DAB9692
P 10050 1300
F 0 "J6" H 10022 1274 50  0000 R CNN
F 1 "HC-10" H 10022 1183 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 10050 1300 50  0001 C CNN
F 3 "~" H 10050 1300 50  0001 C CNN
	1    10050 1300
	-1   0    0    -1  
$EndComp
NoConn ~ 9850 1100
Wire Wire Line
	9850 1200 9600 1200
Wire Wire Line
	9850 1300 9350 1300
Wire Wire Line
	9350 1300 9350 1650
Wire Wire Line
	9650 1400 9850 1400
Wire Wire Line
	9650 1500 9850 1500
$Comp
L power:+5VA #PWR027
U 1 1 5DC55639
P 7700 1150
F 0 "#PWR027" H 7700 1000 50  0001 C CNN
F 1 "+5VA" H 7715 1323 50  0000 C CNN
F 2 "" H 7700 1150 50  0001 C CNN
F 3 "" H 7700 1150 50  0001 C CNN
	1    7700 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6625 1200 6625 1150
Wire Wire Line
	6625 1150 7100 1150
Connection ~ 7100 1150
$Comp
L Device:C_Small C11
U 1 1 5DC79638
P 7950 1450
F 0 "C11" H 7700 1500 50  0000 L CNN
F 1 "100nF" H 7600 1400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7950 1450 50  0001 C CNN
F 3 "~" H 7950 1450 50  0001 C CNN
	1    7950 1450
	-1   0    0    1   
$EndComp
$Comp
L Device:L_Small L1
U 1 1 5DC83DCF
P 7400 1350
F 0 "L1" H 7448 1396 50  0000 L CNN
F 1 "10μH" H 7448 1305 50  0000 L CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7400 1350 50  0001 C CNN
F 3 "~" H 7400 1350 50  0001 C CNN
	1    7400 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 1250 7400 1150
Wire Wire Line
	7400 1150 7300 1150
Wire Wire Line
	7400 1450 7400 1550
Wire Wire Line
	7700 1550 7400 1550
Connection ~ 7400 1550
Wire Wire Line
	7400 1550 7400 1600
Wire Wire Line
	7950 1350 7950 1275
Wire Wire Line
	7950 1275 7700 1275
Wire Wire Line
	7950 1575 7950 1550
$Comp
L power:GND #PWR028
U 1 1 5DCBB2CF
P 7950 1575
F 0 "#PWR028" H 7950 1325 50  0001 C CNN
F 1 "GND" H 7955 1402 50  0000 C CNN
F 2 "" H 7950 1575 50  0001 C CNN
F 3 "" H 7950 1575 50  0001 C CNN
	1    7950 1575
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 1150 7700 1275
Connection ~ 7700 1275
Wire Wire Line
	7700 1275 7700 1550
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5DD0774A
P 4100 1375
F 0 "J3" H 4175 1475 50  0000 L CNN
F 1 "X-AXIS" H 4175 1375 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4100 1375 50  0001 C CNN
F 3 "~" H 4100 1375 50  0001 C CNN
	1    4100 1375
	-1   0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR014
U 1 1 5DD1B1B6
P 4350 1150
F 0 "#PWR014" H 4350 1000 50  0001 C CNN
F 1 "+5VA" H 4365 1323 50  0000 C CNN
F 2 "" H 4350 1150 50  0001 C CNN
F 3 "" H 4350 1150 50  0001 C CNN
	1    4350 1150
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5DD1B6E6
P 4575 1825
F 0 "#PWR017" H 4575 1575 50  0001 C CNN
F 1 "GND" H 4580 1652 50  0000 C CNN
F 2 "" H 4575 1825 50  0001 C CNN
F 3 "" H 4575 1825 50  0001 C CNN
	1    4575 1825
	-1   0    0    -1  
$EndComp
NoConn ~ 7900 3100
NoConn ~ 7900 3800
NoConn ~ 7900 3900
NoConn ~ 7900 4000
NoConn ~ 7900 4100
NoConn ~ 7900 4200
NoConn ~ 7900 4300
NoConn ~ 7900 1900
Wire Wire Line
	7900 2800 8200 2800
Text Label 8200 2800 0    50   ~ 0
ADC0
Wire Wire Line
	7900 2900 8200 2900
Text Label 8200 2900 0    50   ~ 0
ADC1
Wire Wire Line
	7900 3000 8200 3000
Text Label 8200 3000 0    50   ~ 0
ADC2
Text Label 5000 1375 0    50   ~ 0
ADC0
Wire Wire Line
	4300 1275 4350 1275
Wire Wire Line
	4350 1275 4350 1150
$Comp
L Device:C_Small C5
U 1 1 5DD97FB3
P 4800 1575
F 0 "C5" H 4550 1625 50  0000 L CNN
F 1 "100nF" H 4450 1525 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4800 1575 50  0001 C CNN
F 3 "~" H 4800 1575 50  0001 C CNN
	1    4800 1575
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4300 1375 4450 1375
$Comp
L Device:R_Small R1
U 1 1 5DD9B0D0
P 4550 1375
F 0 "R1" V 4400 1375 50  0000 C CNN
F 1 "220R" V 4475 1375 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4550 1375 50  0001 C CNN
F 3 "~" H 4550 1375 50  0001 C CNN
	1    4550 1375
	0    -1   1    0   
$EndComp
Wire Wire Line
	4650 1375 4800 1375
Wire Wire Line
	4800 1375 4800 1475
Wire Wire Line
	4800 1375 5000 1375
Connection ~ 4800 1375
Wire Wire Line
	4800 1675 4800 1750
Wire Wire Line
	4800 1750 4575 1750
Wire Wire Line
	4575 1750 4575 1825
Wire Wire Line
	4575 1750 4350 1750
Wire Wire Line
	4350 1750 4350 1475
Wire Wire Line
	4350 1475 4300 1475
Connection ~ 4575 1750
$Comp
L Connector_Generic:Conn_01x03 J4
U 1 1 5DE5D4D3
P 4100 2725
F 0 "J4" H 4200 2825 50  0000 C CNN
F 1 "Y-AXIS" H 4300 2725 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4100 2725 50  0001 C CNN
F 3 "~" H 4100 2725 50  0001 C CNN
	1    4100 2725
	-1   0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR015
U 1 1 5DE5D4DD
P 4350 2500
F 0 "#PWR015" H 4350 2350 50  0001 C CNN
F 1 "+5VA" H 4365 2673 50  0000 C CNN
F 2 "" H 4350 2500 50  0001 C CNN
F 3 "" H 4350 2500 50  0001 C CNN
	1    4350 2500
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5DE5D4E7
P 4575 3175
F 0 "#PWR018" H 4575 2925 50  0001 C CNN
F 1 "GND" H 4580 3002 50  0000 C CNN
F 2 "" H 4575 3175 50  0001 C CNN
F 3 "" H 4575 3175 50  0001 C CNN
	1    4575 3175
	-1   0    0    -1  
$EndComp
Text Label 5000 2725 0    50   ~ 0
ADC1
Wire Wire Line
	4300 2625 4350 2625
Wire Wire Line
	4350 2625 4350 2500
$Comp
L Device:C_Small C6
U 1 1 5DE5D4F4
P 4800 2925
F 0 "C6" H 4550 2975 50  0000 L CNN
F 1 "100nF" H 4450 2875 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4800 2925 50  0001 C CNN
F 3 "~" H 4800 2925 50  0001 C CNN
	1    4800 2925
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4300 2725 4450 2725
$Comp
L Device:R_Small R2
U 1 1 5DE5D4FF
P 4550 2725
F 0 "R2" V 4400 2725 50  0000 C CNN
F 1 "220R" V 4475 2725 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4550 2725 50  0001 C CNN
F 3 "~" H 4550 2725 50  0001 C CNN
	1    4550 2725
	0    -1   1    0   
$EndComp
Wire Wire Line
	4650 2725 4800 2725
Wire Wire Line
	4800 2725 4800 2825
Wire Wire Line
	4800 2725 5000 2725
Connection ~ 4800 2725
Wire Wire Line
	4800 3025 4800 3100
Wire Wire Line
	4800 3100 4575 3100
Wire Wire Line
	4575 3100 4575 3175
Wire Wire Line
	4575 3100 4350 3100
Wire Wire Line
	4350 3100 4350 2825
Wire Wire Line
	4350 2825 4300 2825
Connection ~ 4575 3100
$Comp
L Connector_Generic:Conn_01x03 J5
U 1 1 5DEAFE95
P 4100 4100
F 0 "J5" H 4200 4200 50  0000 C CNN
F 1 "Z-AXIS" H 4300 4100 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4100 4100 50  0001 C CNN
F 3 "~" H 4100 4100 50  0001 C CNN
	1    4100 4100
	-1   0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR016
U 1 1 5DEAFE9F
P 4350 3875
F 0 "#PWR016" H 4350 3725 50  0001 C CNN
F 1 "+5VA" H 4365 4048 50  0000 C CNN
F 2 "" H 4350 3875 50  0001 C CNN
F 3 "" H 4350 3875 50  0001 C CNN
	1    4350 3875
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 5DEAFEA9
P 4575 4550
F 0 "#PWR019" H 4575 4300 50  0001 C CNN
F 1 "GND" H 4580 4377 50  0000 C CNN
F 2 "" H 4575 4550 50  0001 C CNN
F 3 "" H 4575 4550 50  0001 C CNN
	1    4575 4550
	-1   0    0    -1  
$EndComp
Text Label 5000 4100 0    50   ~ 0
ADC2
Wire Wire Line
	4300 4000 4350 4000
Wire Wire Line
	4350 4000 4350 3875
$Comp
L Device:C_Small C7
U 1 1 5DEAFEB6
P 4800 4300
F 0 "C7" H 4550 4350 50  0000 L CNN
F 1 "100nF" H 4450 4250 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4800 4300 50  0001 C CNN
F 3 "~" H 4800 4300 50  0001 C CNN
	1    4800 4300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4300 4100 4450 4100
$Comp
L Device:R_Small R3
U 1 1 5DEAFEC1
P 4550 4100
F 0 "R3" V 4400 4100 50  0000 C CNN
F 1 "220R" V 4475 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4550 4100 50  0001 C CNN
F 3 "~" H 4550 4100 50  0001 C CNN
	1    4550 4100
	0    -1   1    0   
$EndComp
Wire Wire Line
	4650 4100 4800 4100
Wire Wire Line
	4800 4100 4800 4200
Wire Wire Line
	4800 4100 5000 4100
Connection ~ 4800 4100
Wire Wire Line
	4800 4400 4800 4475
Wire Wire Line
	4800 4475 4575 4475
Wire Wire Line
	4575 4475 4575 4550
Wire Wire Line
	4575 4475 4350 4475
Wire Wire Line
	4350 4475 4350 4200
Wire Wire Line
	4350 4200 4300 4200
Connection ~ 4575 4475
Text Notes 4300 800  0    79   ~ 0
Joystick
Wire Notes Line
	5500 600  5500 4850
Wire Notes Line
	5500 4850 3575 4850
Wire Notes Line
	3575 4850 3575 600 
Wire Notes Line
	3575 600  5500 600 
NoConn ~ 9850 1600
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E0311CE
P 7950 1150
F 0 "#FLG0101" H 7950 1225 50  0001 C CNN
F 1 "PWR_FLAG" H 8100 1325 50  0000 C CNN
F 2 "" H 7950 1150 50  0001 C CNN
F 3 "~" H 7950 1150 50  0001 C CNN
	1    7950 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 1150 7950 1275
Connection ~ 7950 1275
$Comp
L power:+BATT #PWR0101
U 1 1 5E0871CA
P 1350 1150
F 0 "#PWR0101" H 1350 1000 50  0001 C CNN
F 1 "+BATT" H 1365 1323 50  0000 C CNN
F 2 "" H 1350 1150 50  0001 C CNN
F 3 "" H 1350 1150 50  0001 C CNN
	1    1350 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0102
U 1 1 5E0A8EF0
P 1050 2850
F 0 "#PWR0102" H 1050 2700 50  0001 C CNN
F 1 "+BATT" H 1065 3023 50  0000 C CNN
F 2 "" H 1050 2850 50  0001 C CNN
F 3 "" H 1050 2850 50  0001 C CNN
	1    1050 2850
	1    0    0    -1  
$EndComp
$EndSCHEMATC