clear, close all;

% importeer data
vx = importdata('O2_vectors_x.txt','\t');
vy = importdata('O2_vectors_y.txt','\t');
S = importdata('O2_stream.txt','\t');
P = importdata('O2_potential.txt','\t');

% initialiseer grid
minX = -4; maxX = 4;
minY = -2; maxY = 2;
[nY,nX] = size(S);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

% plot: snelheidsvectoren & stroomlijnen
figure(1), hold on;
streamslice(X,Y,vx,vy,5)

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Source in Uniforme stroom:','Stroomlijnen \psi & Snelheidsvectoren'})
daspect([1 1 1])% alternatief: set(gca,'DataAspectRatio',[1 1 1])

% aanduiden source & stagnatiepunt
xsource = -1;
ysource = 0;
xstag = xsource-6/(2*pi*1);
source = plot(xsource,ysource,'g.','MarkerSize',25)
stag = plot(xstag,ysource,'k.','MarkerSize',25)

legend([source,stag],'Source','Stagnatiepunt')

% Toon met simulatie aan waar stagnatiepunt is:
v = (vx.^2+vy.^2).^(1/2);
figure(2), hold on;
contourf(X,Y,v,linspace(-1, 10, 50))
source = plot(xsource,ysource,'m.','MarkerSize',25)
stag = plot(xstag,ysource,'c.','MarkerSize',25)
legend([source,stag],'Source','Stagnatiepunt')
colorbar
ylabel(colorbar,'Norm van de snelheidsvector')
set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Source in Uniforme stroom:','Norm van Snelheidsvector'})
daspect([1 1 1])