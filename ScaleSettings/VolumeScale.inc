[Metadata]
Name=VolumeScale
Author=Lucky Penny
Information=Display the bar used for manipulating the scale of the Volume widget
License=Creative Commons BY-NC-SA 3.0
Version=0.0.3

;------------------------------------------------------------------------------
; Measures

[VolumeScale_MeasureScale]
Measure=Calc
Formula=#ScaleVolume#
MaxValue=2.0
MinValue=0.9

[VolumeScale_MeasureScaleUp]
Measure=Calc
Formula=#ScaleVolume# < 2.0 ? #ScaleVolume# + 0.1 : #ScaleVolume#

[VolumeScale_MeasureScaleDown]
Measure=Calc
Formula=#ScaleVolume# > 1.0 ? #ScaleVolume# - 0.1 : #ScaleVolume#

;------------------------------------------------------------------------------
; Meters

[VolumeScale_Text]
Meter=String
MeasureName=VolumeScale_MeasureScale
StringAlign=Right
X=([SkinSizing:W]-10)
Y=0r
W=42
H=20
AntiAlias=1
FontColor=#TextColor#
FontSize=14
Text=%1x
NumOfDecimals=1

[VolumeScale_MeterVolumeBar]
Meter=Bar
MeterStyle=BarStyle
MeasureName=VolumeScale_MeasureScale
X=-190r
Y=0r
W=143
H=20
MouseScrollUpAction=[!WriteKeyValue Variables ScaleVolume [VolumeScale_MeasureScaleUp] "#@#variables.var"][!RefreshGroup Volume]
MouseScrollDownAction=[!WriteKeyValue Variables ScaleVolume [VolumeScale_MeasureScaleDown] "#@#variables.var"][!RefreshGroup Volume]
DynamicVariables=1

[VolumeScale_MeterSet1.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.0" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.0line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet1.1]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.1" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.1line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet1.2]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.2" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.2line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet1.3]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.3" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.3line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet1.4]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.4" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.4line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet1.5]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.5" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.5line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet1.6]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.6" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.6line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet1.7]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.7" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.7line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet1.8]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.8" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.8line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet1.9]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "1.9" "#@#variables.var"][!RefreshGroup Volume]

[VolumeScale_MeterSet1.9line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[VolumeScale_MeterSet2.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleVolume "2.0" "#@#variables.var"][!RefreshGroup Volume]
