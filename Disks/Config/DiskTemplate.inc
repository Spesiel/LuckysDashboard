[Disk1LetterInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1LetterInput:X]
Y=[Disk1LetterInput:Y]
W=[Disk1LetterInput:W]
H=[Disk1LetterInput:H]
DefaultValue=#Disk1Letter#
Command1=!WriteKeyValue Variables Disk1Letter "$UserInput$" "#@#globalsettings.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

[Disk1SmartSensorIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1SmartSensorInstanceInput:X]
Y=[Disk1SmartSensorInstanceInput:Y]
W=[Disk1SmartSensorInstanceInput:W]
H=[Disk1SmartSensorInstanceInput:H]
DefaultValue=#Disk1SmartSensorId#
Command1=!WriteKeyValue Variables Disk1SmartSensorId "$UserInput$" "#@#HWiNFO.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

[Disk1SmartInstanceInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1SmartTemperatureIdInput:X]
Y=[Disk1SmartTemperatureIdInput:Y]
W=[Disk1SmartTemperatureIdInput:W]
H=[Disk1SmartTemperatureIdInput:H]
DefaultValue=#SmartInstance#
Command1=!WriteKeyValue Variables SmartInstance "$UserInput$" "#@#HWiNFO.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

[Disk1SmartTemperatureIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1SmartSensorIdInput:X]
Y=[Disk1SmartSensorIdInput:Y]
W=[Disk1SmartSensorIdInput:W]
H=[Disk1SmartSensorIdInput:H]
DefaultValue=#Disk1SmartTemperatureId#
Command1=!WriteKeyValue Variables Disk1SmartTemperatureId "$UserInput$" "#@#HWiNFO.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

;---------------------------------------

[Disk1Title]
Meter=String
X=10
Y=21r
W=45
H=20
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
Text=Disk1
UpdateDivider=-1

[Disk1LetterInput]
Meter=String
X=55
Y=0r
W=20
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1Letter#
LeftMouseUpAction=!CommandMeasure "Disk1LetterInputMeasure" "ExecuteBatch 1-3"

[Disk1LetterSemicolon]
Meter=String
X=75
Y=0r
W=10
H=20
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
Text=:
UpdateDivider=-1

[Disk1SmartLabel]
Meter=String
X=85
Y=1r
W=50
H=20
FontSize=10
FontColor=#ForegroundColor#
AntiAlias=1
Text=SMART
UpdateDivider=-1

[meterSelect1tempOn]
Meter=Image
X=140
Y=0r
W=14
H=14
SolidColor=#DiskColor1tempOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables 1_DriveTempOnOff "0" "#@#globalsettings.inc"][!WriteKeyValue Variables DiskColor1tempOnSelect #colorGreen# "#@#globalsettings.inc"][!WriteKeyValue Variables DiskColor1tempOffSelect #colorWhiteDimMin# "#@#globalsettings.inc"][!Refresh #CURRENTCONFIG#][!Refresh #Disk1SkinLoc#]

[meterSelect1tempOff]
Meter=Image
X=160
Y=0r
W=14
H=14
SolidColor=#DiskColor1tempOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables 1_DriveTempOnOff "1" "#@#globalsettings.inc"][!WriteKeyValue Variables DiskColor1tempOffSelect #colorRed# "#@#globalsettings.inc"][!WriteKeyValue Variables DiskColor1tempOnSelect #colorWhiteDimMin# "#@#globalsettings.inc"][!Refresh #CURRENTCONFIG#][!Refresh #Disk1SkinLoc#]

[Disk1SmartSensorIdInput]
Meter=String
X=190
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1SmartSensorId#
LeftMouseUpAction=!CommandMeasure "Disk1SmartTemperatureIdInputMeasure" "ExecuteBatch 1-3"

[Disk1SmartSensorInstanceInput]
Meter=String
X=287
Y=0r
W=35
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1SmartInstance#
LeftMouseUpAction=!CommandMeasure "Disk1SmartSensorIdInputMeasure" "ExecuteBatch 1-3"

[Disk1SmartTemperatureIdInput]
Meter=String
X=324
Y=0r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1SmartTemperatureId#
LeftMouseUpAction=!CommandMeasure "Disk1SmartInstanceInputMeasure" "ExecuteBatch 1-3"
