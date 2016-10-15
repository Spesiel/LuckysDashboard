[Metadata]
Name=FortuneScale
Author=Lucky Penny
Information=Display the bar used for manipulating the scale of the Fortune widget
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

;------------------------------------------------------------------------------
; Measures

[FortuneScale_MeasureScale]
Measure=Calc
Formula=#ScaleFortune#
MaxValue=2.0
MinValue=0.9

[FortuneScale_MeasureScaleUp]
Measure=Calc
Formula=#ScaleFortune# < 2.0 ? #ScaleFortune# + 0.1 : #ScaleFortune#

[FortuneScale_MeasureScaleDown]
Measure=Calc
Formula=#ScaleFortune# > 1.0 ? #ScaleFortune# - 0.1 : #ScaleFortune#

;------------------------------------------------------------------------------
; Meters

[FortuneScale_Text]
Meter=String
MeasureName=FortuneScale_MeasureScale
StringAlign=Right
X=390
Y=0r
W=42
H=20
AntiAlias=1
FontColor=#TextColor#
FontSize=14
Text=%1x
NumOfDecimals=1

[FortuneScale_MeterFortuneBar]
Meter=Bar
MeterStyle=BarStyle
MeasureName=FortuneScale_MeasureScale
X=-190r
Y=0r
W=143
H=20
MouseScrollUpAction=[!WriteKeyValue Variables ScaleFortune [FortuneScale_MeasureScaleUp] "#@#variables.var"][!RefreshGroup Fortune]
MouseScrollDownAction=[!WriteKeyValue Variables ScaleFortune [FortuneScale_MeasureScaleDown] "#@#variables.var"][!RefreshGroup Fortune]
DynamicVariables=1

[FortuneScale_MeterSet1.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.0" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.0line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet1.1]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.1" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.1line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet1.2]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.2" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.2line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet1.3]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.3" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.3line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet1.4]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.4" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.4line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet1.5]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.5" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.5line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet1.6]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.6" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.6line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet1.7]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.7" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.7line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet1.8]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.8" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.8line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet1.9]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "1.9" "#@#variables.var"][!RefreshGroup Fortune]

[FortuneScale_MeterSet1.9line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[FortuneScale_MeterSet2.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleFortune "2.0" "#@#variables.var"][!RefreshGroup Fortune]
