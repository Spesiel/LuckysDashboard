[Metadata]
Name=GpuScale
Author=Lucky Penny
Information=Display the bar used for manipulating the scale of the Gpu widget
License=Creative Commons BY-NC-SA 3.0
Version=0.0.3

;------------------------------------------------------------------------------
; Measures

[GpuScale_MeasureScale]
Measure=Calc
Formula=#ScaleGpu#
MaxValue=2.0
MinValue=0.9

[GpuScale_MeasureScaleUp]
Measure=Calc
Formula=#ScaleGpu# < 2.0 ? #ScaleGpu# + 0.1 : #ScaleGpu#

[GpuScale_MeasureScaleDown]
Measure=Calc
Formula=#ScaleGpu# > 1.0 ? #ScaleGpu# - 0.1 : #ScaleGpu#

;------------------------------------------------------------------------------
; Meters

[GpuScale_Text]
Meter=String
MeasureName=GpuScale_MeasureScale
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

[GpuScale_MeterGpuBar]
Meter=Bar
MeterStyle=BarStyle
MeasureName=GpuScale_MeasureScale
X=-190r
Y=0r
W=143
H=20
MouseScrollUpAction=[!WriteKeyValue Variables ScaleGpu [GpuScale_MeasureScaleUp] "#@#variables.var"][!RefreshGroup Gpu]
MouseScrollDownAction=[!WriteKeyValue Variables ScaleGpu [GpuScale_MeasureScaleDown] "#@#variables.var"][!RefreshGroup Gpu]
DynamicVariables=1

[GpuScale_MeterSet1.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.0" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.0line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet1.1]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.1" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.1line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet1.2]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.2" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.2line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet1.3]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.3" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.3line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet1.4]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.4" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.4line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet1.5]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.5" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.5line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet1.6]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.6" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.6line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet1.7]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.7" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.7line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet1.8]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.8" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.8line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet1.9]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "1.9" "#@#variables.var"][!RefreshGroup Gpu]

[GpuScale_MeterSet1.9line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[GpuScale_MeterSet2.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleGpu "2.0" "#@#variables.var"][!RefreshGroup Gpu]
