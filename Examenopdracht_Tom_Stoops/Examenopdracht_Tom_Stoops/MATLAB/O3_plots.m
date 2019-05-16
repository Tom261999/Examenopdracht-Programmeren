close all;
%% Deel 1
clear;

% importeer data
vx = importdata('O3_D1_vectors_x.txt','\t');
vy = importdata('O3_D1_vectors_y.txt','\t');
S = importdata('O3_D1_stream.txt','\t');
P = importdata('O3_D1_potential.txt','\t');
cp = importdata('O3_D1_drukcoeff.txt','\t');

% initialiseer grid
minX = -2; maxX = 2;
minY = -1; maxY = 1;
[nY,nX] = size(S);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

% plot: snelheidsvectoren & stroomlijnen
figure(1), hold on;
streamslice(X,Y,vx,vy,5)

% labels
source = plot(-1,0,'g.','MarkerSize',25)
sink = plot(1,0,'r.','MarkerSize',25)
legend([source,sink],'Source','Sink')

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Source-Sink in Uniforme stroom (met U_{\infty} = |Q_1| = |Q_2|) :','Stroomlijnen \psi & Snelheidsvectoren'})
daspect([1 1 1])

% plot: drukcoefficient
figure(2), hold on;
contourf(X,Y,cp,linspace(-2, 2, 20))
source = plot(-1,0,'g.','MarkerSize',25)
sink = plot(1,0,'r.','MarkerSize',25)
legend([source,sink],'Source','Sink')
colorbar
ylabel(colorbar,'Drukcoëfficiënt C_p')
set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Source-Sink in Uniforme stroom (met U_{\infty} = |Q_1| = |Q_2|) :','Drukcoëfficiënt C_p'})
daspect([1 1 1])

%% Deel 2
clear;

% plot
figure(3), hold on;

% data import
vx = importdata('O3_D2_vectors_x.txt','\t');
vy = importdata('O3_D2_vectors_y.txt','\t');
%S = importdata('O3_D2_stream.txt','\t');
%P = importdata('O3_D2_potential.txt','\t');

% initialiseer grid
minX = -2; maxX = 2;
minY = -1; maxY = 1;
[nY,nX] = size(vx);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

streamslice(X,Y,vx,vy,5)

% labels
source = plot(-1,0,'g.','MarkerSize',25)
sink = plot(1,0,'r.','MarkerSize',25)
legend([source,sink],'Source','Sink')

%set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Source-Sink in Uniforme stroom (met |Q_1| > |Q_2| = U_\infty):','Stroomlijnen \psi & Snelheidsvectoren'},'FontSize',11)
daspect([1 1 1])
 