% DSP portfølge 2
clear;
close;
clc;

num = [0.01031 0.06188 0.1547 0.2063 0.1547 0.06188 0.01031]; %tæller poly
dnum = [1 -1.188 1.305 -0.6743 0.2635 -0.05175 0.005023]; %nævner poly

[sos, g] = tf2sos(dnum, num, 'down', 'none')
H1num = sos(1:1,1:3);
H1den = sos(1:1,4:6);
H2num = sos(2:2,1:3);
H2den = sos(2:2,4:6);
H3num = sos(3:3,1:3);
H3den = sos(3:3,4:6);
%spejlvend vektorer så de kan bruges til simulink
H1num = fliplr(H1num)
H1den = fliplr(H1den)
H2num = fliplr(H2num)
H2den = fliplr(H2den)
H3num = fliplr(H3num)
H3den = fliplr(H3den)