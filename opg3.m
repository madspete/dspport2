% DSP portfølje 2
clear;
clc;
close;
num = [0.01031 0.06188 0.1547 0.2063 0.1547 0.06188 0.01031]; %tæller poly
dnum = [1 -1.188 1.305 -0.6743 0.2635 -0.05175 0.005023]; %nævner poly

%opgave 3
n = (0:20)
%impuls-respons
%Find partial-brøksoplsnings konstanter
dim = [0.01031 0.06188 0.1547 0.2063 0.1547 0.06188 0.01031]; %tæller poly
nim = [1 -1.188 1.305 -0.6743 0.2635 -0.05175 0.005023 0]; %nævner poly
[rim, pim, kim] = residue(dim,nim)
rim; %konstanter
pim; %poler
kim; %et polynomial som lægges til brøkerne; [2 1 0] svarer til 2x²+x+0
% graf
hn = rim(1)*pim(1).^n + rim(2)*pim(2).^n + rim(3)*pim(3).^n + rim(4)*pim(4).^n +rim(5)*pim(5).^n + rim(6)*pim(6).^n + rim(7)*pim(7).^n;
%hn = 2*abs(rim(1))*(abs(pim(1)).^n).*cos(n.*angle(pim(1))+angle(rim(1))) + 2*abs(rim(3))*(abs(pim(3)).^n).*cos(n.*angle(pim(3))+angle(rim(3))) + 2*abs(rim(5))*(abs(pim(5)).^n).*cos(n.*angle(pim(5))+angle(rim(5)));
subplot(2,2,1)
stem(n,hn)
title('impuls respons udregnet')
[h_i,t] = impz(num, dnum, 21)
subplot(2,2,3)
stem(n,h_i)
title('impuls respons (impz)')

%step-respons
dstep = [dim 0];
nstep = [1 -2.188 2.493 -1.9793 0.9378 -0.31525 0.056773 -0.005023 0]; %nævner poly
[rstep, pstep, kstep] = residue(dstep,nstep); %nævner er samme om impuls-respons
rstep;
pstep;
kstep;
%graf
un = rstep(1)*pstep(1).^ + rstep(1)*pstep(1).^n + rstep(2)*pstep(2).^n + rstep(3)*pstep(3).^n + rstep(4)*pstep(4).^n + rstep(5)*pstep(5).^n + rstep(6)*pstep(6).^n + rstep(7)*pstep(7).^n + rstep(8)*pstep(8).^n;
%un = 
subplot(2,2,2)
stem(n, abs(un))
xlabel('n')
title('step respons udregnet')

[h_s,t] = stepz(num, dnum, 21)
subplot(2,2,4)
stem(n,h_s)
title('step respons (stepz)')

