clear;
%% Deel 1

% importeer data
vx = importdata('O6_D1_vectors_x.txt','\t');
vy = importdata('O6_D1_vectors_y.txt','\t');
S = importdata('O6_D1_stream.txt','\t');
P = importdata('O6_D1_potential.txt','\t');
cp = importdata('O6_D1_drukcoeff.txt','\t');

% initialiseer grid
minX = -2; maxX = 2;
minY = -1; maxY = 1;
[nY,nX] = size(S);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

% plot: snelheidsvectoren & stroomlijnen
figure(1), hold on, box on;
streamslice(X,Y,vx,vy,5)

% labels
object = plot(0,0,'k.','MarkerSize',25)
legend([object],'Vortex + Doublet')

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Lift op een Vortex:','Stroomlijnen \psi & Snelheidsvectoren'})
daspect([1 1 1])
axis([-2 2 -1 1])

% moet dit?
% % % plot: drukcoefficient
% % figure(2), hold on, box on;
% % contourf(X,Y,abs(cp),linspace(-2, 2, 20))
% % object = plot(0,0,'k.','MarkerSize',25)
% % legend([object],'Vortex + Doublet')
% % colorbar
% % ylabel(colorbar,'Drukcoëfficiënt C_p')
% % set(gca,'FontSize',11)
% % xlabel('x-as')
% % ylabel('y-as')
% % title({'Lift op een Vortex:','Drukcoëfficiënt C_p'})
% % daspect([1 1 1])

%% Deel 2

% importeer data
vx = importdata('O6_D2_vectors_x.txt','\t');
vy = importdata('O6_D2_vectors_y.txt','\t');
S = importdata('O6_D2_stream.txt','\t');
P = importdata('O6_D2_potential.txt','\t');

% initialiseer grid
minX = -2; maxX = 2;
minY = -1; maxY = 1;
[nY,nX] = size(S);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

% plot: snelheidsvectoren & stroomlijnen
figure(2), hold on, box on;
streamslice(X,Y,vx,vy,5)

% labels
object = plot(0,0,'k.','MarkerSize',25)
legend([object],'Vortex + Doublet')

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Lift op een Vortex (niet voldaan aan criterium):','Stroomlijnen \psi & Snelheidsvectoren'})
daspect([1 1 1])
axis([-2 2 -1 1])