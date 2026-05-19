# Automated LN2 Project
Arduino-based LN2 dispensing assistant for OSU IEEE Overclocking Club that measures liquid nitrogen output in real time during dewar fills.

Problem: LN2 vapor obscures visibility during fills, making it difficult to see how much has been dispensed/how full the dewar is.

Solution: Interface a lab-grade scale with an Arduino through RS-232 to TTL serial conversion to output real-time mass data. A button driven UI lets the user set a target dispense amount, an alarm is triggered when the target mass is reached.

Hardware: Arduino, RS-232 to TTL converter, lab-grade tank and scale, buzzer, buttons, lcd screen

Status: In progress, working on RS-232 to TTL serial conversion
