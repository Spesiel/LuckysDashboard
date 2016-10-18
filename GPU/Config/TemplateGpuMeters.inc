[|Title]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=5
Y=10R
Text=|

[|SensorIdMeasureInput]
Measure=Plugin
Plugin=InputText
X=[|SensorIdText:X]
Y=[|SensorIdText:Y]
H=[|SensorIdText:H]
W=[|SensorIdText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|SensorId#
Command1=[!WriteKeyValue Variables |SensorId "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|SensorIdLabel]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=10R
Y=0r
Text=Sensor ID
UpdateDivider=-1

[|SensorIdText]
Meter=String
FontSize=10
X=5R
Y=0r
W=90
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|SensorId#
LeftMouseUpAction=!CommandMeasure "|SensorIdMeasureInput" "ExecuteBatch 1-2"

[|CoreInstanceMeasureInput]
Measure=Plugin
Plugin=InputText
X=[|CoreInstanceText:X]
Y=[|CoreInstanceText:Y]
H=[|CoreInstanceText:H]
W=[|CoreInstanceText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|CoreInstance#
Command1=[!WriteKeyValue Variables |CoreInstance "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|CoreInstanceLabel]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=10R
Y=0r
Text=Instance
UpdateDivider=-1

[|CoreInstanceText]
Meter=String
FontSize=10
X=5R
Y=0r
W=40
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|CoreInstance#
LeftMouseUpAction=!CommandMeasure "|CoreInstanceMeasureInput" "ExecuteBatch 1-2"

[|CoreUsageEntryIdMeasureInput]
Measure=Plugin
Plugin=InputText
X=[|CoreUsageEntryIdText:X]
Y=[|CoreUsageEntryIdText:Y]
H=[|CoreUsageEntryIdText:H]
W=[|CoreUsageEntryIdText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|CoreUsageEntryId#
Command1=[!WriteKeyValue Variables |CoreUsageEntryId "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|CoreUsageEntryIdLabel]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=([|Title:X]+35)
Y=([|Title:Y]+40)
Text=Core Usage
UpdateDivider=-1

[|CoreUsageEntryIdText]
Meter=String
FontSize=10
X=5R
Y=0r
W=90
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|CoreUsageEntryId#
LeftMouseUpAction=!CommandMeasure "|CoreUsageEntryIdMeasureInput" "ExecuteBatch 1-2"

[|CoreClockEntryIdMeasureInput]
Measure=Plugin
Plugin=InputText
X=[|CoreClockEntryIdText:X]
Y=[|CoreClockEntryIdText:Y]
H=[|CoreClockEntryIdText:H]
W=[|CoreClockEntryIdText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|CoreClockEntryId#
Command1=[!WriteKeyValue Variables |CoreClockEntryId "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|CoreClockEntryIdLabel]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=10R
Y=([|Title:Y]+40)
Text=Clock
UpdateDivider=-1

[|CoreClockEntryIdText]
Meter=String
FontSize=10
X=5R
Y=0r
W=90
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|CoreClockEntryId#
LeftMouseUpAction=!CommandMeasure "|CoreClockEntryIdMeasureInput" "ExecuteBatch 1-2"

[|TempEntryIdMeasureInput]
Measure=Plugin
Plugin=InputText
X=[|TempEntryIdText:X]
Y=[|TempEntryIdText:Y]
H=[|TempEntryIdText:H]
W=[|TempEntryIdText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|TempEntryId#
Command1=[!WriteKeyValue Variables |TempEntryId "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|TempEntryIdLabel]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=10R
Y=([|Title:Y]+40)
Text=Temp
UpdateDivider=-1

[|TempEntryIdText]
Meter=String
FontSize=10
X=5R
Y=0r
W=90
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|TempEntryId#
LeftMouseUpAction=!CommandMeasure "|TempEntryIdMeasureInput" "ExecuteBatch 1-2"

[|MeasureFanDisabled]
Measure=Calc
Formula=#|FanOffRpmPercent#>0?0:1
IfCondition=(|MeasureFanDisabled=0)
IfTrueAction=[!HideMeterGroup |FanOffRpm][!DisableMeasureGroup |FanOffRpm][!HideMeterGroup |FanOffPct][!DisableMeasureGroup |FanOffPct]

[|MeasureFanRpm]
Measure=Calc
Formula=#|FanOffRpmPercent#=1?0:1
IfCondition=(|MeasureFanRpm=0)
IfTrueAction=[!ShowMeterGroup |FanOffRpm][!EnableMeasureGroup |FanOffRpm][!HideMeterGroup |FanOffPct][!DisableMeasureGroup |FanOffPct]
IfFalseAction=[!HideMeterGroup |FanOffRpm][!DisableMeasureGroup |FanOffRpm]

[|MeasureFanPct]
Measure=Calc
Formula=#|FanOffRpmPercent#=2?0:1
IfCondition=(|MeasureFanPct=0)
IfTrueAction=[!HideMeterGroup |FanOffRpm][!DisableMeasureGroup |FanOffRpm][!ShowMeterGroup |FanOffPct][!EnableMeasureGroup |FanOffPct]
IfFalseAction=[!HideMeterGroup |FanOffPct][!DisableMeasureGroup |FanOffPct]

[|FanOffRpmPercentLabel]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=([|Title:X]+35)
Y=([|Title:Y]+60)
Text=Fan
UpdateDivider=-1

[|FanSetOff]
Meter=String
MeterStyle=TextStyle
StringAlign=CenterCenter
FontSize=10
X=35R
Y=9r
W=70
H=22
SolidColor=#|FanSetOff#
Text=Off
LeftMouseUpAction=[!WriteKeyValue Variables |FanOffRpmPercent 0 "#@#gpus.var"][!WriteKeyValue Variables |FanSetOff #BackdropColor# "#@#gpus.var"][!WriteKeyValue Variables |FanSetRpm #ColorClear# "#@#gpus.var"][!WriteKeyValue Variables |FanSetPercent #ColorClear# "#@#gpus.var"][!RefreshGroup Gpus]
UpdateDivider=-1

[|FanSetRpm]
Meter=String
MeterStyle=TextStyle
StringAlign=CenterCenter
FontSize=10
X=5R
Y=0r
W=70
H=22
SolidColor=#|FanSetRpm#
Text=RPM
LeftMouseUpAction=[!WriteKeyValue Variables |FanOffRpmPercent 1 "#@#gpus.var"][!WriteKeyValue Variables |FanSetOff #ColorClear# "#@#gpus.var"][!WriteKeyValue Variables |FanSetRpm #BackdropColor# "#@#gpus.var"][!WriteKeyValue Variables |FanSetPercent #ColorClear# "#@#gpus.var"][!RefreshGroup Gpus]
UpdateDivider=-1

[|FanSetPercent]
Meter=String
MeterStyle=TextStyle
StringAlign=CenterCenter
FontSize=10
X=5R
Y=0r
W=70
H=22
SolidColor=#|FanSetPercent#
Text=%
LeftMouseUpAction=[!WriteKeyValue Variables |FanOffRpmPercent 2 "#@#gpus.var"][!WriteKeyValue Variables |FanSetOff #ColorClear# "#@#gpus.var"][!WriteKeyValue Variables |FanSetRpm #ColorClear# "#@#gpus.var"][!WriteKeyValue Variables |FanSetPercent #BackdropColor# "#@#gpus.var"][!RefreshGroup Gpus]
UpdateDivider=-1

[|FanRpmEntryIdMeasureInput]
Group=|FanOffRpm
Measure=Plugin
Plugin=InputText
X=[|FanRpmEntryIdText:X]
Y=[|FanRpmEntryIdText:Y]
H=[|FanRpmEntryIdText:H]
W=[|FanRpmEntryIdText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|FanRpmEntryId#
Command1=[!WriteKeyValue Variables |FanRpmEntryId "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|FanRpmEntryIdLabel]
Group=|FanOffRpm
Meter=String
MeterStyle=TextStyle
FontSize=10
X=372
Y=([|Title:Y]+60)
Text=RPM
UpdateDivider=-1

[|FanRpmEntryIdText]
Group=|FanOffRpm
Meter=String
FontSize=10
X=5R
Y=0r
W=90
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|FanRpmEntryId#
LeftMouseUpAction=!CommandMeasure "|FanRpmEntryIdMeasureInput" "ExecuteBatch 1-2"

[|FanPercentEntryIdMeasureInput]
Group=|FanOffPct
Measure=Plugin
Plugin=InputText
X=[|FanPercentEntryIdText:X]
Y=[|FanPercentEntryIdText:Y]
H=[|FanPercentEntryIdText:H]
W=[|FanPercentEntryIdText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|FanPercentEntryId#
Command1=[!WriteKeyValue Variables |FanPercentEntryId "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|FanPercentEntryIdLabel]
Group=|FanOffPct
Meter=String
MeterStyle=TextStyle
FontSize=10
X=378
Y=([|Title:Y]+60)
Text=Pct
UpdateDivider=-1

[|FanPercentEntryIdText]
Group=|FanOffPct
Meter=String
FontSize=10
X=5R
Y=0r
W=90
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|FanPercentEntryId#
LeftMouseUpAction=!CommandMeasure "|FanPercentEntryIdMeasureInput" "ExecuteBatch 1-2"

[|MeasureMemNVidia]
Measure=Calc
Formula=#|NVidiaAmd#=1?0:1
IfCondition=(|MeasureMemNVidia=0)
IfTrueAction=[!ShowMeterGroup |MemNVidia][!EnableMeasureGroup |MemNVidia][!HideMeterGroup |MemAmd][!DisableMeasureGroup |MemAmd]
IfFalseAction=[!HideMeterGroup |MemNVidia][!DisableMeasureGroup |MemNVidia]

[|MeasureMemAmd]
Measure=Calc
Formula=#|NVidiaAmd#=2?0:1
IfCondition=(|MeasureMemAmd=0)
IfTrueAction=[!HideMeterGroup |MemNVidia][!DisableMeasureGroup |MemNVidia][!ShowMeterGroup |MemAmd][!EnableMeasureGroup |MemAmd]
IfFalseAction=[!HideMeterGroup |MemAmd][!DisableMeasureGroup |MemAmd]

[|NVidiaAmdLabel]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=([|Title:X]+35)
Y=([|Title:Y]+85)
Text=Mem
UpdateDivider=-1

[|NVidiaAmdSetNVidia]
Meter=String
MeterStyle=TextStyle
StringAlign=CenterCenter
FontSize=10
X=35R
Y=9r
W=70
H=22
SolidColor=#|NVidiaAmdSetNVidia#
Text=NVidia
LeftMouseUpAction=[!WriteKeyValue Variables |NVidiaAmd 1 "#@#gpus.var"][!WriteKeyValue Variables |NVidiaAmdSetNVidia #BackdropColor# "#@#gpus.var"][!WriteKeyValue Variables |NVidiaAmdSetAmd #ColorClear# "#@#gpus.var"][!RefreshGroup Gpus]
UpdateDivider=-1

[|NVidiaAmdSetAmd]
Meter=String
MeterStyle=TextStyle
StringAlign=CenterCenter
FontSize=10
X=-5R
Y=0r
W=70
H=22
SolidColor=#|NVidiaAmdSetAmd#
Text=AMD
LeftMouseUpAction=[!WriteKeyValue Variables |NVidiaAmd 2 "#@#gpus.var"][!WriteKeyValue Variables |NVidiaAmdSetNVidia #ColorClear# "#@#gpus.var"][!WriteKeyValue Variables |NVidiaAmdSetAmd #BackdropColor# "#@#gpus.var"][!RefreshGroup Gpus]
UpdateDivider=-1

[|NVidiaMemoryAllocatedEntryIdMeasureInput]
Group=|MemNVidia
Measure=Plugin
Plugin=InputText
X=[|NVidiaMemoryAllocatedEntryIdText:X]
Y=[|NVidiaMemoryAllocatedEntryIdText:Y]
H=[|NVidiaMemoryAllocatedEntryIdText:H]
W=[|NVidiaMemoryAllocatedEntryIdText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|NVidiaMemoryAllocatedEntryId#
Command1=[!WriteKeyValue Variables |NVidiaMemoryAllocatedEntryId "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|NVidiaMemoryAllocatedEntryIdLabel]
Group=|MemNVidia
Meter=String
MeterStyle=TextStyle
FontSize=10
X=210
Y=([|Title:Y]+87)
Text=Allocated
UpdateDivider=-1

[|NVidiaMemoryAllocatedEntryIdText]
Group=|MemNVidia
Meter=String
FontSize=10
X=5R
Y=0r
W=75
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|NVidiaMemoryAllocatedEntryId#
LeftMouseUpAction=!CommandMeasure "|NVidiaMemoryAllocatedEntryIdMeasureInput" "ExecuteBatch 1-2"

[|NVidiaMemoryUsageEntryIdMeasureInput]
Group=|MemNVidia
Measure=Plugin
Plugin=InputText
X=[|NVidiaMemoryUsageEntryIdText:X]
Y=[|NVidiaMemoryUsageEntryIdText:Y]
H=[|NVidiaMemoryUsageEntryIdText:H]
W=[|NVidiaMemoryUsageEntryIdText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|NVidiaMemoryUsageEntryId#
Command1=[!WriteKeyValue Variables |NVidiaMemoryUsageEntryId "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|NVidiaMemoryUsageEntryIdLabel]
Group=|MemNVidia
Meter=String
MeterStyle=TextStyle
FontSize=10
X=7R
Y=([|Title:Y]+85)
Text=Usage
UpdateDivider=-1

[|NVidiaMemoryUsageEntryIdText]
Group=|MemNVidia
Meter=String
FontSize=10
X=5R
Y=0r
W=75
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|NVidiaMemoryUsageEntryId#
LeftMouseUpAction=!CommandMeasure "|NVidiaMemoryUsageEntryIdMeasureInput" "ExecuteBatch 1-2"

[|AMDD3DMemoryDedicatedMeasureInput]
Group=|MemAmd
Measure=Plugin
Plugin=InputText
X=[|AMDD3DMemoryDedicatedText:X]
Y=[|AMDD3DMemoryDedicatedText:Y]
H=[|AMDD3DMemoryDedicatedText:H]
W=[|AMDD3DMemoryDedicatedText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|AMDD3DMemoryDedicated#
Command1=[!WriteKeyValue Variables |AMDD3DMemoryDedicated "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|AMDD3DMemoryDedicatedLabel]
Group=|MemAmd
Meter=String
MeterStyle=TextStyle
FontSize=10
X=221
Y=([|Title:Y]+87)
Text=Dedicated
UpdateDivider=-1

[|AMDD3DMemoryDedicatedText]
Group=|MemAmd
Meter=String
FontSize=10
X=5R
Y=0r
W=75
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|AMDD3DMemoryDedicated#
LeftMouseUpAction=!CommandMeasure "|AMDD3DMemoryDedicatedMeasureInput" "ExecuteBatch 1-2"

[|AMDD3DMemoryTotalMeasureInput]
Group=|MemAmd
Measure=Plugin
Plugin=InputText
X=[|AMDD3DMemoryTotalText:X]
Y=[|AMDD3DMemoryTotalText:Y]
H=[|AMDD3DMemoryTotalText:H]
W=[|AMDD3DMemoryTotalText:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#|AMDD3DMemoryTotal#
Command1=[!WriteKeyValue Variables |AMDD3DMemoryTotal "$UserInput$" "#@#gpus.var"]
Command2=!RefreshGroup Gpus

[|AMDD3DMemoryTotalLabel]
Group=|MemAmd
Meter=String
MeterStyle=TextStyle
FontSize=10
X=7R
Y=([|Title:Y]+87)
Text=Total
UpdateDivider=-1

[|AMDD3DMemoryTotalText]
Group=|MemAmd
Meter=String
FontSize=10
X=5R
Y=0r
W=75
H=16
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|AMDD3DMemoryTotal#
LeftMouseUpAction=!CommandMeasure "|AMDD3DMemoryTotalMeasureInput" "ExecuteBatch 1-2"
[|Positioner]
Meter=Image
X=([|NVidiaAmdLabel:X])
Y=([|NVidiaAmdLabel:Y])
W=([|NVidiaAmdLabel:W])
H=([|NVidiaAmdLabel:H])
SolidColor=#ColorClear#
DynamicVariables=1