EESchema Schematic File Version 4
EELAYER 26 0
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
L Device:R R1
U 1 1 6273E9A3
P 9550 6000
F 0 "R1" V 9550 6000 50  0000 C CNN
F 1 "470R" V 9434 6000 50  0001 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9480 6000 50  0001 C CNN
F 3 "~" H 9550 6000 50  0001 C CNN
	1    9550 6000
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 6273EA71
P 9550 5900
F 0 "R2" V 9550 5900 50  0000 C CNN
F 1 "R" V 9434 5900 50  0001 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9480 5900 50  0001 C CNN
F 3 "~" H 9550 5900 50  0001 C CNN
	1    9550 5900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 6273FB48
P 6950 3800
F 0 "#PWR0102" H 6950 3550 50  0001 C CNN
F 1 "GND" H 6955 3627 50  0000 C CNN
F 2 "" H 6950 3800 50  0001 C CNN
F 3 "" H 6950 3800 50  0001 C CNN
	1    6950 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 6273FC2B
P 5750 5400
F 0 "C1" H 5865 5446 50  0000 L CNN
F 1 "100n" H 5865 5355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5788 5250 50  0001 C CNN
F 3 "~" H 5750 5400 50  0001 C CNN
	1    5750 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 6273FDBF
P 5750 5750
F 0 "#PWR0103" H 5750 5500 50  0001 C CNN
F 1 "GND" H 5755 5577 50  0000 C CNN
F 2 "" H 5750 5750 50  0001 C CNN
F 3 "" H 5750 5750 50  0001 C CNN
	1    5750 5750
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0104
U 1 1 6273FE42
P 5750 5100
F 0 "#PWR0104" H 5750 4950 50  0001 C CNN
F 1 "+3V3" H 5765 5273 50  0000 C CNN
F 2 "" H 5750 5100 50  0001 C CNN
F 3 "" H 5750 5100 50  0001 C CNN
	1    5750 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 5550 5750 5600
Wire Wire Line
	5750 5250 5750 5150
Wire Wire Line
	5500 4850 5500 5150
Wire Wire Line
	5500 5150 5750 5150
Connection ~ 5750 5150
Wire Wire Line
	5400 4850 5400 5600
Wire Wire Line
	5400 5600 5750 5600
Connection ~ 5750 5600
Wire Wire Line
	5750 5600 5750 5750
Wire Wire Line
	5750 5150 5750 5100
$Comp
L Device:C C3
U 1 1 62740397
P 3700 1500
F 0 "C3" H 3815 1546 50  0000 L CNN
F 1 "100n" H 3815 1455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3738 1350 50  0001 C CNN
F 3 "~" H 3700 1500 50  0001 C CNN
	1    3700 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 6274039D
P 3700 1850
F 0 "#PWR0105" H 3700 1600 50  0001 C CNN
F 1 "GND" H 3705 1677 50  0000 C CNN
F 2 "" H 3700 1850 50  0001 C CNN
F 3 "" H 3700 1850 50  0001 C CNN
	1    3700 1850
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0106
U 1 1 627403A3
P 3700 1200
F 0 "#PWR0106" H 3700 1050 50  0001 C CNN
F 1 "+3V3" H 3715 1373 50  0000 C CNN
F 2 "" H 3700 1200 50  0001 C CNN
F 3 "" H 3700 1200 50  0001 C CNN
	1    3700 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 627405A2
P 6700 2650
F 0 "C4" H 6815 2696 50  0000 L CNN
F 1 "100n" H 6815 2605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6738 2500 50  0001 C CNN
F 3 "~" H 6700 2650 50  0001 C CNN
	1    6700 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 627405A8
P 6700 3000
F 0 "#PWR0107" H 6700 2750 50  0001 C CNN
F 1 "GND" H 6705 2827 50  0000 C CNN
F 2 "" H 6700 3000 50  0001 C CNN
F 3 "" H 6700 3000 50  0001 C CNN
	1    6700 3000
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0108
U 1 1 627405AE
P 6700 2350
F 0 "#PWR0108" H 6700 2200 50  0001 C CNN
F 1 "+3V3" H 6715 2523 50  0000 C CNN
F 2 "" H 6700 2350 50  0001 C CNN
F 3 "" H 6700 2350 50  0001 C CNN
	1    6700 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 2800 6700 2850
Wire Wire Line
	6700 2500 6700 2400
Connection ~ 6700 2400
Wire Wire Line
	6350 2850 6700 2850
Connection ~ 6700 2850
Wire Wire Line
	6700 2850 6700 3000
Wire Wire Line
	6700 2400 6700 2350
$Comp
L Device:C C2
U 1 1 6274079F
P 3250 3900
F 0 "C2" H 3365 3946 50  0000 L CNN
F 1 "100n" H 3365 3855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3288 3750 50  0001 C CNN
F 3 "~" H 3250 3900 50  0001 C CNN
	1    3250 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 627407A5
P 3250 4250
F 0 "#PWR0109" H 3250 4000 50  0001 C CNN
F 1 "GND" H 3255 4077 50  0000 C CNN
F 2 "" H 3250 4250 50  0001 C CNN
F 3 "" H 3250 4250 50  0001 C CNN
	1    3250 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0110
U 1 1 627407AB
P 3250 3600
F 0 "#PWR0110" H 3250 3450 50  0001 C CNN
F 1 "+3V3" H 3265 3773 50  0000 C CNN
F 2 "" H 3250 3600 50  0001 C CNN
F 3 "" H 3250 3600 50  0001 C CNN
	1    3250 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 2850 6350 3150
Wire Wire Line
	6350 3150 5900 3150
Wire Wire Line
	5900 2400 5900 3050
Wire Wire Line
	5900 2400 6700 2400
Wire Wire Line
	3700 1200 3700 1300
Wire Wire Line
	3700 1650 3700 1750
Wire Wire Line
	4500 2050 4500 1300
Wire Wire Line
	4500 1300 3700 1300
Connection ~ 3700 1300
Wire Wire Line
	3700 1300 3700 1350
Wire Wire Line
	4600 2050 4600 1750
Wire Wire Line
	4600 1750 3700 1750
Connection ~ 3700 1750
Wire Wire Line
	3700 1750 3700 1850
Wire Wire Line
	3250 3600 3250 3700
Wire Wire Line
	3250 4050 3250 4150
Wire Wire Line
	3250 4150 3700 4150
Wire Wire Line
	3700 4150 3700 3750
Wire Wire Line
	3700 3750 4100 3750
Connection ~ 3250 4150
Wire Wire Line
	3250 4150 3250 4250
Wire Wire Line
	3250 3700 3900 3700
Wire Wire Line
	3900 3700 3900 3850
Wire Wire Line
	3900 3850 4100 3850
Connection ~ 3250 3700
Wire Wire Line
	3250 3700 3250 3750
$Comp
L power:+5V #PWR0111
U 1 1 627445DA
P 9000 4350
F 0 "#PWR0111" H 9000 4200 50  0001 C CNN
F 1 "+5V" H 9015 4523 50  0000 C CNN
F 2 "" H 9000 4350 50  0001 C CNN
F 3 "" H 9000 4350 50  0001 C CNN
	1    9000 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 62744615
P 9100 5000
F 0 "#PWR0112" H 9100 4750 50  0001 C CNN
F 1 "GND" H 9105 4827 50  0000 C CNN
F 2 "" H 9100 5000 50  0001 C CNN
F 3 "" H 9100 5000 50  0001 C CNN
	1    9100 5000
	1    0    0    -1  
$EndComp
Text Label 8500 4600 0    50   ~ 0
D+
Text Label 8500 4700 0    50   ~ 0
D-
Wire Wire Line
	5900 3350 6200 3350
Wire Wire Line
	5900 3450 6200 3450
Text Label 6100 3350 0    50   ~ 0
D+
Text Label 6100 3450 0    50   ~ 0
D-
Wire Wire Line
	9100 2900 9400 2900
Wire Wire Line
	9100 3000 9400 3000
Wire Wire Line
	9100 3100 9400 3100
Wire Wire Line
	9100 3200 9400 3200
Wire Wire Line
	7700 2900 7450 2900
Wire Wire Line
	7700 3000 7450 3000
Wire Wire Line
	7700 3100 7450 3100
Text Label 9150 2900 0    50   ~ 0
CLK
Text Label 9150 3000 0    50   ~ 0
GND
Text Label 9150 3100 0    50   ~ 0
D0
Text Label 9150 3200 0    50   ~ 0
D1
Text Label 7550 2900 0    50   ~ 0
D2
Text Label 7550 3000 0    50   ~ 0
D3
Text Label 7550 3100 0    50   ~ 0
CMD
Wire Wire Line
	4700 4850 4700 5050
Wire Wire Line
	5900 3750 6150 3750
Wire Wire Line
	5900 3650 6150 3650
Wire Wire Line
	5300 2050 5300 1750
Wire Wire Line
	5200 2050 5200 1750
Wire Wire Line
	5900 3850 6150 3850
Text Label 4700 5000 1    50   ~ 0
CMD
Text Label 6000 3650 0    50   ~ 0
D2
Text Label 6000 3750 0    50   ~ 0
D1
Text Label 6000 3850 0    50   ~ 0
CLK
Text Label 5200 1950 1    50   ~ 0
D3
Text Label 5300 1950 1    50   ~ 0
D0
Wire Wire Line
	9000 4350 9000 4800
Wire Wire Line
	9100 4500 9100 5000
$Comp
L ASMT-YTB2-0BB02:ASMT-YTB2-0BB02 LED1
U 1 1 6275A9B6
P 7850 5800
F 0 "LED1" H 8550 6065 50  0000 C CNN
F 1 "ASMT-YTB2-0BB02" H 8550 5974 50  0000 C CNN
F 2 "ASMT-YTB2-0BB02:ASMT-YTC7-0AA02" H 9100 5900 50  0001 L CNN
F 3 "http://www.mouser.com/datasheet/2/678/V02-2583EN_DS_ASMT-YTB2-0BB02_2018-03-26-1359910.pdf" H 9100 5800 50  0001 L CNN
F 4 "Broadcom ASMT-YTB2-0BB02, 470 / 530 / 622 nm 3 RGB LED, PLCC 6 SMD package" H 9100 5700 50  0001 L CNN "Description"
F 5 "" H 9100 5600 50  0001 L CNN "Height"
F 6 "Avago Technologies" H 9100 5500 50  0001 L CNN "Manufacturer_Name"
F 7 "ASMT-YTB2-0BB02" H 9100 5400 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "630-ASMT-YTB2-0BB02" H 9100 5300 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Broadcom-Avago/ASMT-YTB2-0BB02?qs=wmFqszA%252Be7NbgAs1Z53pjg%3D%3D" H 9100 5200 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 9100 5100 50  0001 L CNN "Arrow Part Number"
F 11 "" H 9100 5000 50  0001 L CNN "Arrow Price/Stock"
	1    7850 5800
	1    0    0    -1  
$EndComp
$Comp
L ASM1117CD-5.0:ASM1117CD-5.0 IC2
U 1 1 6275AAE9
P 1450 5500
F 0 "IC2" H 2300 5765 50  0000 C CNN
F 1 "ASM1117CD-3.3" H 2300 5674 50  0000 C CNN
F 2 "ASM1117CD-5.0:SOT229P700X180-4N" H 3000 5600 50  0001 L CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 3000 5500 50  0001 L CNN
F 4 "1A LOW DROPOUT VOLTAGE REGULATOR" H 3000 5400 50  0001 L CNN "Description"
F 5 "1.8" H 3000 5300 50  0001 L CNN "Height"
F 6 "Advanced Monolithic Systems" H 3000 5200 50  0001 L CNN "Manufacturer_Name"
F 7 "ASM1117CD-3.3" H 3000 5100 50  0001 L CNN "Manufacturer_Part_Number"
	1    1450 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3000 3950 3450
Wire Wire Line
	3950 3450 4100 3450
Wire Wire Line
	1750 3100 1750 3350
Wire Wire Line
	1750 3350 3800 3350
Wire Wire Line
	3800 3350 3800 3550
Wire Wire Line
	3800 3550 4100 3550
$Comp
L Device:C C5
U 1 1 6275F638
P 1750 3700
F 0 "C5" H 1865 3746 50  0000 L CNN
F 1 "12p" H 1865 3655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1788 3550 50  0001 C CNN
F 3 "~" H 1750 3700 50  0001 C CNN
	1    1750 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 3350 1750 3550
Connection ~ 1750 3350
$Comp
L power:GND #PWR0113
U 1 1 62760C1A
P 1750 4050
F 0 "#PWR0113" H 1750 3800 50  0001 C CNN
F 1 "GND" H 1755 3877 50  0000 C CNN
F 2 "" H 1750 4050 50  0001 C CNN
F 3 "" H 1750 4050 50  0001 C CNN
	1    1750 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 3850 1750 4050
$Comp
L Device:C C6
U 1 1 62762265
P 2300 3700
F 0 "C6" H 2415 3746 50  0000 L CNN
F 1 "12p" H 2415 3655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2338 3550 50  0001 C CNN
F 3 "~" H 2300 3700 50  0001 C CNN
	1    2300 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 6276235F
P 2300 4050
F 0 "#PWR0114" H 2300 3800 50  0001 C CNN
F 1 "GND" H 2305 3877 50  0000 C CNN
F 2 "" H 2300 4050 50  0001 C CNN
F 3 "" H 2300 4050 50  0001 C CNN
	1    2300 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3850 2300 4050
Wire Wire Line
	3700 3000 3700 3300
Wire Wire Line
	3700 3300 2300 3300
Wire Wire Line
	2300 3300 2300 3550
Connection ~ 3700 3000
Wire Wire Line
	3700 3000 3950 3000
$Comp
L power:GND #PWR0115
U 1 1 62765F03
P 3250 6250
F 0 "#PWR0115" H 3250 6000 50  0001 C CNN
F 1 "GND" H 3255 6077 50  0000 C CNN
F 2 "" H 3250 6250 50  0001 C CNN
F 3 "" H 3250 6250 50  0001 C CNN
	1    3250 6250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0116
U 1 1 62766364
P 1050 5350
F 0 "#PWR0116" H 1050 5200 50  0001 C CNN
F 1 "+5V" H 1065 5523 50  0000 C CNN
F 2 "" H 1050 5350 50  0001 C CNN
F 3 "" H 1050 5350 50  0001 C CNN
	1    1050 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 5700 1050 5700
Wire Wire Line
	1050 5700 1050 5350
$Comp
L power:+3V3 #PWR0117
U 1 1 6276974C
P 1400 5350
F 0 "#PWR0117" H 1400 5200 50  0001 C CNN
F 1 "+3V3" H 1415 5523 50  0000 C CNN
F 2 "" H 1400 5350 50  0001 C CNN
F 3 "" H 1400 5350 50  0001 C CNN
	1    1400 5350
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0118
U 1 1 62769775
P 3250 5300
F 0 "#PWR0118" H 3250 5150 50  0001 C CNN
F 1 "+3V3" H 3265 5473 50  0000 C CNN
F 2 "" H 3250 5300 50  0001 C CNN
F 3 "" H 3250 5300 50  0001 C CNN
	1    3250 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 627697E4
P 3250 6000
F 0 "C8" H 3365 6046 50  0000 L CNN
F 1 "1u" H 3365 5955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3288 5850 50  0001 C CNN
F 3 "~" H 3250 6000 50  0001 C CNN
	1    3250 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 627698A6
P 1050 5950
F 0 "C7" H 1165 5996 50  0000 L CNN
F 1 "1u" H 1165 5905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1088 5800 50  0001 C CNN
F 3 "~" H 1050 5950 50  0001 C CNN
	1    1050 5950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 62769A8E
P 1050 6200
F 0 "#PWR0119" H 1050 5950 50  0001 C CNN
F 1 "GND" H 1055 6027 50  0000 C CNN
F 2 "" H 1050 6200 50  0001 C CNN
F 3 "" H 1050 6200 50  0001 C CNN
	1    1050 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 6100 1050 6150
Wire Wire Line
	1050 5800 1050 5700
Connection ~ 1050 5700
Wire Wire Line
	1450 5500 1300 5500
Wire Wire Line
	1300 5500 1300 6150
Wire Wire Line
	1300 6150 1050 6150
Connection ~ 1050 6150
Wire Wire Line
	1050 6150 1050 6200
Wire Wire Line
	1400 5350 1400 5600
Wire Wire Line
	1400 5600 1450 5600
Wire Wire Line
	3250 5850 3250 5500
Wire Wire Line
	3150 5500 3250 5500
Connection ~ 3250 5500
Wire Wire Line
	3250 5500 3250 5300
Wire Wire Line
	3250 6250 3250 6150
$Comp
L Device:R R3
U 1 1 6277CC33
P 9550 5800
F 0 "R3" V 9550 5800 50  0000 C CNN
F 1 "R" V 9434 5800 50  0001 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9480 5800 50  0001 C CNN
F 3 "~" H 9550 5800 50  0001 C CNN
	1    9550 5800
	0    1    1    0   
$EndComp
Wire Wire Line
	5900 3250 6200 3250
Wire Wire Line
	5600 2050 5600 1750
Text Label 5600 1950 1    50   ~ 0
DEB-CLK
Text Label 6100 3250 0    50   ~ 0
DEB-IO
Wire Wire Line
	7400 1750 7750 1750
Wire Wire Line
	7400 1850 7750 1850
Text Label 7700 1750 2    50   ~ 0
DEB-CLK
Text Label 7450 1850 0    50   ~ 0
DEB-IO
$Comp
L Mechanical:MountingHole H1
U 1 1 62790547
P 800 7550
F 0 "H1" H 900 7596 50  0000 L CNN
F 1 "MountingHole" H 900 7505 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2" H 800 7550 50  0001 C CNN
F 3 "~" H 800 7550 50  0001 C CNN
	1    800  7550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 62790613
P 1300 7550
F 0 "H2" H 1400 7596 50  0000 L CNN
F 1 "MountingHole" H 1400 7505 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2" H 1300 7550 50  0001 C CNN
F 3 "~" H 1300 7550 50  0001 C CNN
	1    1300 7550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 62790EBE
P 4000 4550
F 0 "C9" H 4115 4596 50  0000 L CNN
F 1 "100n" H 4115 4505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4038 4400 50  0001 C CNN
F 3 "~" H 4000 4550 50  0001 C CNN
	1    4000 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 62790F2A
P 4000 4850
F 0 "#PWR0120" H 4000 4600 50  0001 C CNN
F 1 "GND" H 4005 4677 50  0000 C CNN
F 2 "" H 4000 4850 50  0001 C CNN
F 3 "" H 4000 4850 50  0001 C CNN
	1    4000 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 4700 4000 4850
Wire Wire Line
	4000 3650 4100 3650
Wire Wire Line
	4000 3650 4000 4400
$Comp
L Device:R R4
U 1 1 62798D6B
P 5050 1250
F 0 "R4" V 4950 1250 50  0000 C CNN
F 1 "10k" V 4934 1250 50  0001 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4980 1250 50  0001 C CNN
F 3 "~" H 5050 1250 50  0001 C CNN
	1    5050 1250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 62799015
P 5250 1350
F 0 "#PWR0121" H 5250 1100 50  0001 C CNN
F 1 "GND" H 5255 1177 50  0000 C CNN
F 2 "" H 5250 1350 50  0001 C CNN
F 3 "" H 5250 1350 50  0001 C CNN
	1    5250 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1250 5250 1250
Wire Wire Line
	5250 1250 5250 1350
Wire Wire Line
	4900 2050 4900 1250
$Comp
L power:GND #PWR0122
U 1 1 627A0DD1
P 1500 3150
F 0 "#PWR0122" H 1500 2900 50  0001 C CNN
F 1 "GND" H 1505 2977 50  0000 C CNN
F 2 "" H 1500 3150 50  0001 C CNN
F 3 "" H 1500 3150 50  0001 C CNN
	1    1500 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 627A0E08
P 3550 3150
F 0 "#PWR0123" H 3550 2900 50  0001 C CNN
F 1 "GND" H 3555 2977 50  0000 C CNN
F 2 "" H 3550 3150 50  0001 C CNN
F 3 "" H 3550 3150 50  0001 C CNN
	1    3550 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3150 3550 3100
Wire Wire Line
	1500 3150 1500 3000
$Comp
L power:GND #PWR0124
U 1 1 627A7294
P 6850 4850
F 0 "#PWR0124" H 6850 4600 50  0001 C CNN
F 1 "GND" H 6855 4677 50  0000 C CNN
F 2 "" H 6850 4850 50  0001 C CNN
F 3 "" H 6850 4850 50  0001 C CNN
	1    6850 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 4850 6850 4600
Wire Wire Line
	6850 4500 6950 4500
Wire Wire Line
	6950 4600 6850 4600
Connection ~ 6850 4600
Wire Wire Line
	6850 4600 6850 4500
$Comp
L power:+3V3 #PWR0101
U 1 1 6273FB15
P 6950 3100
F 0 "#PWR0101" H 6950 2950 50  0001 C CNN
F 1 "+3V3" H 6965 3273 50  0000 C CNN
F 2 "" H 6950 3100 50  0001 C CNN
F 3 "" H 6950 3100 50  0001 C CNN
	1    6950 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 627B0857
P 6950 3500
F 0 "C10" H 7065 3546 50  0000 L CNN
F 1 "1u" H 7065 3455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6988 3350 50  0001 C CNN
F 3 "~" H 6950 3500 50  0001 C CNN
	1    6950 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 627B09F3
P 7300 3500
F 0 "C11" H 7415 3546 50  0000 L CNN
F 1 "100n" H 7415 3455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7338 3350 50  0001 C CNN
F 3 "~" H 7300 3500 50  0001 C CNN
	1    7300 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 3100 6950 3200
Wire Wire Line
	6950 3650 6950 3800
Wire Wire Line
	6950 3200 7300 3200
Connection ~ 6950 3200
Wire Wire Line
	6950 3200 6950 3350
$Comp
L power:GND #PWR0125
U 1 1 627BA2A3
P 7300 3800
F 0 "#PWR0125" H 7300 3550 50  0001 C CNN
F 1 "GND" H 7305 3627 50  0000 C CNN
F 2 "" H 7300 3800 50  0001 C CNN
F 3 "" H 7300 3800 50  0001 C CNN
	1    7300 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 3350 7300 3200
Connection ~ 7300 3200
Wire Wire Line
	7300 3200 7700 3200
Wire Wire Line
	7300 3800 7300 3650
$Comp
L power:GND #PWR0126
U 1 1 627C10CF
P 4100 2250
F 0 "#PWR0126" H 4100 2000 50  0001 C CNN
F 1 "GND" H 4105 2077 50  0000 C CNN
F 2 "" H 4100 2250 50  0001 C CNN
F 3 "" H 4100 2250 50  0001 C CNN
	1    4100 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2050 4100 2050
Wire Wire Line
	4100 2050 4100 2250
$Comp
L Device:C C15
U 1 1 627C4A98
P 5150 6050
F 0 "C15" H 5265 6096 50  0000 L CNN
F 1 "1u" H 5265 6005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5188 5900 50  0001 C CNN
F 3 "~" H 5150 6050 50  0001 C CNN
	1    5150 6050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 627C4FFD
P 4850 6050
F 0 "C14" H 4965 6096 50  0000 L CNN
F 1 "1u" H 4965 6005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4888 5900 50  0001 C CNN
F 3 "~" H 4850 6050 50  0001 C CNN
	1    4850 6050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 627C5049
P 4550 6050
F 0 "C13" H 4665 6096 50  0000 L CNN
F 1 "1u" H 4665 6005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4588 5900 50  0001 C CNN
F 3 "~" H 4550 6050 50  0001 C CNN
	1    4550 6050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 627C5097
P 4250 6050
F 0 "C12" H 4365 6096 50  0000 L CNN
F 1 "1u" H 4365 6005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4288 5900 50  0001 C CNN
F 3 "~" H 4250 6050 50  0001 C CNN
	1    4250 6050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0127
U 1 1 627C50EB
P 5150 6350
F 0 "#PWR0127" H 5150 6100 50  0001 C CNN
F 1 "GND" H 5155 6177 50  0000 C CNN
F 2 "" H 5150 6350 50  0001 C CNN
F 3 "" H 5150 6350 50  0001 C CNN
	1    5150 6350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0128
U 1 1 627C512E
P 4850 6350
F 0 "#PWR0128" H 4850 6100 50  0001 C CNN
F 1 "GND" H 4855 6177 50  0000 C CNN
F 2 "" H 4850 6350 50  0001 C CNN
F 3 "" H 4850 6350 50  0001 C CNN
	1    4850 6350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0129
U 1 1 627C5171
P 4550 6350
F 0 "#PWR0129" H 4550 6100 50  0001 C CNN
F 1 "GND" H 4555 6177 50  0000 C CNN
F 2 "" H 4550 6350 50  0001 C CNN
F 3 "" H 4550 6350 50  0001 C CNN
	1    4550 6350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0130
U 1 1 627C51B4
P 4250 6350
F 0 "#PWR0130" H 4250 6100 50  0001 C CNN
F 1 "GND" H 4255 6177 50  0000 C CNN
F 2 "" H 4250 6350 50  0001 C CNN
F 3 "" H 4250 6350 50  0001 C CNN
	1    4250 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 5800 4250 5900
Wire Wire Line
	4550 5900 4550 5800
Connection ~ 4550 5800
Wire Wire Line
	4550 5800 4250 5800
Wire Wire Line
	4850 5900 4850 5800
Wire Wire Line
	4550 5800 4850 5800
Connection ~ 4850 5800
Wire Wire Line
	4850 5800 5150 5800
Wire Wire Line
	5150 5900 5150 5800
Connection ~ 5150 5800
Wire Wire Line
	5150 5800 5300 5800
Wire Wire Line
	4250 6350 4250 6200
Wire Wire Line
	4850 6350 4850 6200
Wire Wire Line
	5150 6350 5150 6200
Wire Wire Line
	4550 6200 4550 6350
$Comp
L Device:C C16
U 1 1 627EA1BB
P 9350 4650
F 0 "C16" H 9465 4696 50  0000 L CNN
F 1 "1u" H 9465 4605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9388 4500 50  0001 C CNN
F 3 "~" H 9350 4650 50  0001 C CNN
	1    9350 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 4800 9000 4800
Connection ~ 9000 4800
Wire Wire Line
	9350 4500 9100 4500
Connection ~ 9100 4500
$Comp
L LFXTAL069392Cutt:LFXTAL069392Cutt Y1
U 1 1 627F3E6E
P 1850 3000
F 0 "Y1" H 2650 3265 50  0000 C CNN
F 1 "LFXTAL069392Cutt" H 2650 3174 50  0000 C CNN
F 2 "LFXTAL069392Cutt:LFXTAL069392Cutt" H 3300 3100 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/1/LFXTAL069392Cutt.pdf" H 3300 3000 50  0001 L CNN
F 4 "Crystals 16.0MHz 2.6 x 2.1 x 0.6mm" H 3300 2900 50  0001 L CNN "Description"
F 5 "0.6" H 3300 2800 50  0001 L CNN "Height"
F 6 "IQD" H 3300 2700 50  0001 L CNN "Manufacturer_Name"
F 7 "LFXTAL069392Cutt" H 3300 2600 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "449-LFXTAL069392CUTT" H 3300 2500 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/IQD/LFXTAL069392Cutt?qs=nFovR%252B4R4UNxw2KKrfwNAQ%3D%3D" H 3300 2400 50  0001 L CNN "Mouser Price/Stock"
F 10 "LFXTAL069392CUTT" H 3300 2300 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/lfxtal069392cutt/iqd-frequency-products" H 3300 2200 50  0001 L CNN "Arrow Price/Stock"
	1    1850 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 3000 1850 3000
Wire Wire Line
	1850 3100 1750 3100
Wire Wire Line
	3450 3000 3700 3000
Wire Wire Line
	3450 3100 3550 3100
$Comp
L power:+3V3 #PWR0131
U 1 1 62810098
P 7700 5600
F 0 "#PWR0131" H 7700 5450 50  0001 C CNN
F 1 "+3V3" H 7715 5773 50  0000 C CNN
F 2 "" H 7700 5600 50  0001 C CNN
F 3 "" H 7700 5600 50  0001 C CNN
	1    7700 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 5600 7700 5800
Wire Wire Line
	7700 6000 7850 6000
Wire Wire Line
	7850 5800 7700 5800
Connection ~ 7700 5800
Wire Wire Line
	7700 5800 7700 5900
Wire Wire Line
	7850 5900 7700 5900
Connection ~ 7700 5900
Wire Wire Line
	7700 5900 7700 6000
Wire Wire Line
	9700 6000 10050 6000
Wire Wire Line
	10050 5900 9700 5900
Wire Wire Line
	10050 5800 9700 5800
Wire Wire Line
	5300 4850 5300 5800
Wire Wire Line
	4400 5250 4400 4850
Wire Wire Line
	4500 5250 4500 4850
Wire Wire Line
	4600 5250 4600 4850
Text Label 9800 6000 0    50   ~ 0
LD_R
Text Label 9800 5900 0    50   ~ 0
LD_G
Text Label 9800 5800 0    50   ~ 0
LD_B
Text Label 4400 5100 1    50   ~ 0
LD_R
Text Label 4500 5100 1    50   ~ 0
LD_G
Text Label 4600 5100 1    50   ~ 0
LD_B
$Comp
L USB-AM-S-F-B-TH:USB-AM-S-F-B-TH J2
U 1 1 6286805F
P 6950 4500
F 0 "J2" H 7400 4765 50  0000 C CNN
F 1 "USB-AM-S-F-B-TH" H 7400 4674 50  0000 C CNN
F 2 "test:USBAMSFBTH" H 7700 4600 50  0001 L CNN
F 3 "http://suddendocs.samtec.com/prints/usb-am-s-x-x-th-x-mkt.pdf" H 7700 4500 50  0001 L CNN
F 4 "Conn USB 2.0 Type A PL 4 POS 2mm/2.5mm Solder RA Thru-Hole 4 Terminal 1 Port Bulk" H 7700 4400 50  0001 L CNN "Description"
F 5 "4.6" H 7700 4300 50  0001 L CNN "Height"
F 6 "SAMTEC" H 7700 4200 50  0001 L CNN "Manufacturer_Name"
F 7 "USB-AM-S-F-B-TH" H 7700 4100 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "200-USBAMSFBTH" H 7700 4000 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Samtec/USB-AM-S-F-B-TH?qs=Cqqh%252BS766wkVA4Y1oUegpA%3D%3D" H 7700 3900 50  0001 L CNN "Mouser Price/Stock"
F 10 "USB-AM-S-F-B-TH" H 7700 3800 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/usb-am-s-f-b-th/samtec?region=europe" H 7700 3700 50  0001 L CNN "Arrow Price/Stock"
	1    6950 4500
	1    0    0    -1  
$EndComp
$Comp
L 47352-1001:47352-1001 J1
U 1 1 628695C8
P 7700 2900
F 0 "J1" H 8400 3165 50  0000 C CNN
F 1 "47352-1001" H 8400 3074 50  0000 C CNN
F 2 "test:47352-1001" H 8950 3000 50  0001 L CNN
F 3 "http://www.molex.com/pdm_docs/sd/473521001_sd.pdf" H 8950 2900 50  0001 L CNN
F 4 "Molex 47388 Series 8 Way Right Angle Micro SD Memory Card Connector with Solder Termination" H 8950 2800 50  0001 L CNN "Description"
F 5 "" H 8950 2700 50  0001 L CNN "Height"
F 6 "Molex" H 8950 2600 50  0001 L CNN "Manufacturer_Name"
F 7 "47352-1001" H 8950 2500 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "538-47352-1001" H 8950 2400 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Molex/47352-1001?qs=c2CV6XM0DweyUS%2F9lG4Ycg%3D%3D" H 8950 2300 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 8950 2200 50  0001 L CNN "Arrow Part Number"
F 11 "" H 8950 2100 50  0001 L CNN "Arrow Price/Stock"
	1    7700 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0132
U 1 1 628747E3
P 7050 1500
F 0 "#PWR0132" H 7050 1350 50  0001 C CNN
F 1 "+3V3" H 7065 1673 50  0000 C CNN
F 2 "" H 7050 1500 50  0001 C CNN
F 3 "" H 7050 1500 50  0001 C CNN
	1    7050 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0133
U 1 1 62874828
P 7200 2050
F 0 "#PWR0133" H 7200 1800 50  0001 C CNN
F 1 "GND" H 7205 1877 50  0000 C CNN
F 2 "" H 7200 2050 50  0001 C CNN
F 3 "" H 7200 2050 50  0001 C CNN
	1    7200 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2050 7200 1650
Wire Wire Line
	7200 1650 7750 1650
Wire Wire Line
	7050 1500 7050 1950
Wire Wire Line
	7050 1950 7750 1950
Wire Wire Line
	9250 5800 9400 5800
Wire Wire Line
	9250 5900 9400 5900
Wire Wire Line
	9250 6000 9400 6000
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 62765452
P 7950 1750
F 0 "J3" H 8030 1742 50  0000 L CNN
F 1 "Conn_01x04" H 8030 1651 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Horizontal" H 7950 1750 50  0001 C CNN
F 3 "~" H 7950 1750 50  0001 C CNN
	1    7950 1750
	1    0    0    -1  
$EndComp
$Comp
L STM32F411CEU6:STM32F411CEU6 IC1
U 1 1 62753A84
P 4100 3050
F 0 "IC1" H 5941 2696 50  0000 L CNN
F 1 "STM32F411CEU6" H 5941 2605 50  0000 L CNN
F 2 "test:QFN50P700X700X60-49N-D" H 5750 3850 50  0001 L CNN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/b3/a5/46/3b/b4/e5/4c/85/DM00115249.pdf/files/DM00115249.pdf/jcr:content/translations/en.DM00115249.pdf" H 5750 3750 50  0001 L CNN
F 4 "32-Bit MCU 512K Flash 100MHz UFQFPN48 STMicroelectronics STM32F411CEU6, 32bit ARM Cortex M4 MCU, 100MHz, 512 kB Flash, 48-Pin UFQFPN" H 5750 3650 50  0001 L CNN "Description"
F 5 "0.6" H 5750 3550 50  0001 L CNN "Height"
F 6 "STMicroelectronics" H 5750 3450 50  0001 L CNN "Manufacturer_Name"
F 7 "STM32F411CEU6" H 5750 3350 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "511-STM32F411CEU6" H 5750 3250 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/STMicroelectronics/STM32F411CEU6?qs=pjMTYa9MTGV3ou31YBFa3g%3D%3D" H 5750 3150 50  0001 L CNN "Mouser Price/Stock"
F 10 "STM32F411CEU6" H 5750 3050 50  0001 L CNN "Arrow Part Number"
F 11 "https://www.arrow.com/en/products/stm32f411ceu6/stmicroelectronics?region=nac" H 5750 2950 50  0001 L CNN "Arrow Price/Stock"
	1    4100 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 4500 9100 4500
Wire Wire Line
	7850 4800 9000 4800
$Comp
L Device:R R5
U 1 1 6277EF0A
P 8250 4600
F 0 "R5" V 8250 4600 50  0000 C CNN
F 1 "R" V 8134 4600 50  0001 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8180 4600 50  0001 C CNN
F 3 "~" H 8250 4600 50  0001 C CNN
	1    8250 4600
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 6277EFAC
P 8250 4700
F 0 "R6" V 8250 4700 50  0000 C CNN
F 1 "R" V 8134 4700 50  0001 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8180 4700 50  0001 C CNN
F 3 "~" H 8250 4700 50  0001 C CNN
	1    8250 4700
	0    1    1    0   
$EndComp
Wire Wire Line
	8750 4700 8400 4700
Wire Wire Line
	7850 4700 8100 4700
Wire Wire Line
	7850 4600 8100 4600
Wire Wire Line
	8750 4600 8400 4600
$EndSCHEMATC
