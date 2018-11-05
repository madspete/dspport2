% DSP portfølge 2
clear;
close;
clc;

%opgave 4 Bode plot af H(z)
fs = 8*10e3
%f = logspace(0, 2, 5000);
%w = 2*pi*f;
o_max = pi;
o_min = 0;
presision = 1000;
n = (o_max-o_min)/ presision;
omega = (o_min:n:o_max);
f = (omega/2*pi)*fs;

z = exp(j*omega);

H = (0.01031.*z.^6 + 0.06188.*z.^5 + 0.11547.*z.^4 + 0.2063.*z.^3 + 0.1547.*z.^2 + 0.06188.*z + 0.01031)./(1.*z.^6 - 1.188.*z.^5 + 1.305.*z.^4 - 0.6742.*z.^3 + 0.2635.*z.^2 - 0.05175.*z + 0.005023);
Hdb = 20*log(abs(H));
subplot(2,1,1)
plot(omega, Hdb)
title(' frequency response')
xlabel('omega [rad]')
ylabel('A [dB]')
subplot(2,1,2)
plot(omega, angle(H))
title('phase')
xlabel('omega [rad]')
ylabel('phase [deg]')

%Brug freqz til at finde frekvens respons:
% A = [1 -1.188 1.305 -0.6742 0.2635 -0.05175 0.005023]; %nævner poly i H
% B = [0.01031 0.06188 0.11547 0.2063 0.1547 0.06188 0.01031]; %tæller poly i H
% N = 5000; %antal normal fordelte punkter
% [H,W] = freqz(B,A,N);
% subplot(2,2,2)
% plot(W, 20*log(abs(H)))
% title(' frequency response using freqz()')
% xlabel('omega [rad]')
% ylabel('A [dB]')
% subplot(2,2,4)
% plot(W, angle(H))
% title('phase using freqz()')
% xlabel('omega [rad]')
% ylabel('A [dB]')
