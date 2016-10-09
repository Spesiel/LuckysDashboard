[Metadata]
Name=ClockScale
Author=Lucky Penny
Information=Display the bar used for manipulating the scale of the Clock widgets
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

;------------------------------------------------------------------------------
; Measures

[ClockScale_MeasureScale]
Measure=Calc
Formula=#ScaleClock#
MaxValue=2.0
MinValue=0.9

[ClockScale_MeasureScaleUp]
Measure=Calc
Formula=#ScaleClock# < 2.0 ? #ScaleClock# + 0.1 : #ScaleClock#

[ClockScale_MeasureScaleDown]
Measure=Calc
Formula=#ScaleClock# > 1.0 ? #ScaleClock# - 0.1 : #ScaleClock#

;------------------------------------------------------------------------------
; Meters

[ClockScale_Text]
Meter=String
MeasureName=ClockScale_MeasureScale
StringAlign=Right
X=390
Y=0r
W=42
H=20
AntiAlias=1
FontColor=#ForegroundColor#
FontSize=14
Text=%1x
NumOfDecimals=1

[ClockScale_MeterClockBar]
Meter=Bar
MeterStyle=BarStyle
MeasureName=ClockScale_MeasureScale
X=-190r
Y=0r
W=143
H=20
MouseScrollUpAction=[!WriteKeyValue Variables ScaleClock [ClockScale_MeasureScaleUp] "#@#variables.var"][!RefreshGroup Clocks]
MouseScrollDownAction=[!WriteKeyValue Variables ScaleClock [ClockScale_MeasureScaleDown] "#@#variables.var"][!RefreshGroup Clocks]
DynamicVariables=1

[ClockScale_MeterSet1.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.0" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.0line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet1.1]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.1" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.1line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet1.2]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.2" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.2line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet1.3]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.3" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.3line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet1.4]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.4" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.4line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet1.5]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.5" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.5line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet1.6]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.6" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.6line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet1.7]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.7" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.7line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet1.8]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.8" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.8line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet1.9]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "1.9" "#@#variables.var"][!RefreshGroup Clocks]

[ClockScale_MeterSet1.9line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[ClockScale_MeterSet2.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleClock "2.0" "#@#variables.var"][!RefreshGroup Clocks]
