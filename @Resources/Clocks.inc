[Metadata]
Name=ClocksSettings
Author=Lucky Penny
Information=Variables values for the clocks
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

[Variables]

; Transformation Matrix for ScaleClock
Scaling=#ScaleClock#;0;0;#ScaleClock#;#ScaleClock#;#ScaleClock#

; Clock1 variables
Clock1_Label=PST
Clock1_12or24=I
Clock1_Timezone=-8
Clock1_DST=1

; Clock2 variables
Clock2_Label=France
Clock2_12or24=I
Clock2_Timezone=1
Clock2_DST=1

; Clock3 variables
Clock3_Label=CST
Clock3_12or24=I
Clock3_Timezone=-6
Clock3_DST=1

; Clock4 variables
Clock4_Label=EST
Clock4_12or24=I
Clock4_Timezone=-5
Clock4_DST=1

;------------------------------------------------------------------------------
; Used by the configurators

Clock1_12Select=253,151,31,75
Clock1_24Select=0,0,0,0
Clock1_DSTOnSelect=100,250,100
Clock1_DSTOffSelect=253,151,31,75

Clock2_12Select=253,151,31,75
Clock2_24Select=0,0,0,0
Clock2_DSTOnSelect=100,250,100
Clock2_DSTOffSelect=253,151,31,75

Clock3_12Select=253,151,31,75
Clock3_24Select=0,0,0,0
Clock3_DSTOnSelect=100,250,100
Clock3_DSTOffSelect=253,151,31,75

Clock4_12Select=253,151,31,75
Clock4_24Select=0,0,0,0
Clock4_DSTOnSelect=100,250,100
Clock4_DSTOffSelect=253,151,31,75

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
; Skin sizing

[SkinSizing]
Meter=Image
X=0
Y=0
W=(125*#ScaleClock#)
H=(([MeterTimeSecondsBar:Y]+1+[MeterTimeSecondsBar:H]+5)*#ScaleClock#)
DynamicVariables=1
UpdateDivider=-1
