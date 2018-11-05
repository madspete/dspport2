% DSP portfølge 2
clear;
clc;
close;

datafile = '/home/kasper/Documents/DSP/port2/to_git_rep/dspport2/data.txt';
%input
values = csvread(datafile)
n = (0:(size(values)-1));
values = values.';
stem(n, values)

%overførings funktion
dnum = [0.01031 0.06188 0.1547 0.2063 0.1547 0.06188 0.01031]; %tæller poly
num = [1 -1.188 1.305 -0.6743 0.2635 -0.05175 0.005023]; %nævner poly
Hz = filt(dnum, num)

%find output
[y, t] = lsim(Hz, values);
y
