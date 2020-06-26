# TechDots

Introduction

Many of our labor force are working on ground level emptying the garbage bins whenever they are full.
This has now become a challenge as the amount of garbage produced by our society are continuously
increasing. Our aim is to make this process easier for the labor force by convincing residents to keep the
garbage via a smart dustbin which helps them to generate compost.
Problem

• Because of this nonpattern garbage filling, sometimes the effort and energy are wasted.
• Fuel consumption for the garbage vehicles can be reduced using this.
• Some people find it hard to make compost
• People are avoiding home gardening due to lack of fertilizer

Solution

This system monitors the garbage bins and informs about the level of garbage collected in the garbage
bins to a thingspeak channel. Also, moisture and temperature are collected through a humidity sensor
and will be sent to the channel. The result will be shown in a web view with instructions to improve the
quality of the compost. System uses ultrasonic sensors located with the bin’s lid to detect the garbage
level and relate it with the garbage bins deepness. We also use weight sensors attached below the garbage
bins to identify its weight. The advantage of this is that the garbage bin lifting weight can also be known
by the owner. The system also uses ESP32, LCD screen and a buzzer. The LCD screen is used to display the
status of the level and weight of garbage collected in the bins. Whereas a thingspeak channel to show the
status to the user monitoring it. Also, the weight of the individual bins will be shown along with the level
of the garbage bin. The LCD screen shows the status of the garbage level, moisture and temperature. The
system puts on the buzzer when the level of garbage collected crosses the set limit.

Components

• ESP32
• HC-SR04 Ultrasonic
• Humidity Sensor
• Weight Sensor
• Buzzer
• LCD’s
• Resistors
• Capacitors
• Transistors
• Cables & Connectors
• Diodes
• LED’s
• Supporting frame

Team Members
▪ Nipuna Munasinghe (Team Leader)
▪ Kasuri Abhilashini
▪ Malinga Shenal
