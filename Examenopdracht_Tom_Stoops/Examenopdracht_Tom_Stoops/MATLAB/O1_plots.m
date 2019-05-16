close all;
%% Deel 1
clear;

% importeer data
vx = importdata('O1_D1_vectors_x.txt','\t');
vy = importdata('O1_D1_vectors_y.txt','\t');
S = importdata('O1_D1_stream.txt','\t');
P = importdata('O1_D1_potential.txt','\t');

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
title({'Source-Sink (met |Q_1| = |Q_2|):','Stroomlijnen \psi & Snelheidsvectoren'})
daspect([1 1 1])% alternatief: set(gca,'DataAspectRatio',[1 1 1])

% plot: equipotentiaallijnen
figure(2), hold on;
contourf(X,Y,P,20)
colorbar;

% labels
source = plot(-1,0,'g.','MarkerSize',25)
sink = plot(1,0,'r.','MarkerSize',25)
legend([source,sink],'Source','Sink')

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Source-Sink (met |Q_1| = |Q_2|):','Equipotentiaallijnen \phi'})
colorbar;
ylabel(colorbar,'Potentiaal')
daspect([1 1 1])

% plot: equipotentiaallijnen + stroomlijnen
figure(3), hold on;
contourf(X,Y,P,20)
streamslice(X,Y,vx,vy,1)
colorbar;
ylabel(colorbar,'Potentiaal')

% labels
source = plot(-1,0,'g.','MarkerSize',25)
sink = plot(1,0,'r.','MarkerSize',25)
legend([source,sink],'Source','Sink')

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Source-Sink (met |Q_1| = |Q_2|):','Equipotentiaallijnen \phi & Stroomlijnen \psi'})
daspect([1 1 1])

%% Deel 2
clear;

% importeer de data
vx = importdata('O1_D2_vectors_x.txt','\t');
vy = importdata('O1_D2_vectors_y.txt','\t');
S = importdata('O1_D2_stream.txt','\t');
P = importdata('O1_D2_potential.txt','\t');

% initialiseer grid
minX = -2; maxX = 2;
minY = -1; maxY = 1;
[nY,nX] = size(S);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

% plot: snelheidsvectoren & stroomlijnen
figure(4), hold on;
streamslice(X,Y,vx,vy,5)

% labels
source = plot(-1,0,'g.','MarkerSize',25)
sink = plot(1,0,'r.','MarkerSize',25)
legend([source,sink],'Source','Sink')

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Source-Sink (met |Q_1| > |Q_2|):','Stroomlijnen \psi & Snelheidsvectoren'})
daspect([1 1 1])

%% Deel 3
clear;

% plots: Q*l = cte
figure(5);

subplot(4,1,1), hold on;
    % data import
    vx = importdata('O1_D3_1_vectors_x.txt','\t');
    vy = importdata('O1_D3_1_vectors_y.txt','\t');
    %S = importdata('O1_D3_1_stream.txt','\t');
    %P = importdata('O1_D3_1_potential.txt','\t');
    
    % initialiseer grid
    minX = -2; maxX = 2;
    minY = -1; maxY = 1;
    [nY,nX] = size(vx);
    [X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));
    
    streamslice(X,Y,vx,vy,5)
    
    % labels
    source = plot(-0.5,0,'g.','MarkerSize',25)
    sink = plot(0.5,0,'r.','MarkerSize',25)
    legend([source,sink],'Source','Sink')

    %set(gca,'FontSize',11)
    xlabel('x-as')
    ylabel('y-as')
    title({'Source-Sink (met |Q_1| = |Q_2| en Q*l = c^{te}):','Stroomlijnen \psi & Snelheidsvectoren'},'FontSize',11)
    daspect([1 1 1])
    
subplot(4,1,2), hold on;
    % data import
    vx = importdata('O1_D3_2_vectors_x.txt','\t');
    vy = importdata('O1_D3_2_vectors_y.txt','\t');
    %S = importdata('O1_D3_2_stream.txt','\t');
    %P = importdata('O1_D3_2_potential.txt','\t');
    
    % initialiseer grid
    minX = -2; maxX = 2;
    minY = -1; maxY = 1;
    [nY,nX] = size(vx);
    [X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));
    
    streamslice(X,Y,vx,vy,5)
    
    % labels
    source2 = plot(-0.25,0,'g.','MarkerSize',25)
    sink2 = plot(0.25,0,'r.','MarkerSize',25)
    legend([source2,sink2],'Source','Sink')

    %set(gca,'FontSize',11)
    xlabel('x-as')
    ylabel('y-as')
    %title({'Source-Sink (met |Q_1| = |Q_2| en Q*l = c^{te}):','Stroomlijnen \psi & Snelheidsvectoren'},'FontSize',11)
    daspect([1 1 1])
    
subplot(4,1,3), hold on;
    % data import
    vx = importdata('O1_D3_3_vectors_x.txt','\t');
    vy = importdata('O1_D3_3_vectors_y.txt','\t');
    %S = importdata('O1_D3_3_stream.txt','\t');
    %P = importdata('O1_D3_3_potential.txt','\t');
    
    % initialiseer grid
    minX = -2; maxX = 2;
    minY = -1; maxY = 1;
    [nY,nX] = size(vx);
    [X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));
    
    streamslice(X,Y,vx,vy,5)
    
    % labels
    source3 = plot(-0.125,0,'g.','MarkerSize',25)
    sink3 = plot(0.125,0,'r.','MarkerSize',25)
    legend([source3,sink3],'Source','Sink')

    %set(gca,'FontSize',11)
    xlabel('x-as')
    ylabel('y-as')
    %title({'Source-Sink (met |Q_1| = |Q_2| en Q*l = c^{te}):','Stroomlijnen \psi & Snelheidsvectoren'},'FontSize',11)
    daspect([1 1 1])

subplot(4,1,4), hold on;
    % data import
    vx = importdata('O1_D3_4_vectors_x.txt','\t');
    vy = importdata('O1_D3_4_vectors_y.txt','\t');
    %S = importdata('O1_D3_4_stream.txt','\t');
    %P = importdata('O1_D3_4_potential.txt','\t');
    
    % initialiseer grid
    minX = -2; maxX = 2;
    minY = -1; maxY = 1;
    [nY,nX] = size(vx);
    [X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));
    
    streamslice(X,Y,vx,vy,5)
    
    % labels
    source4 = plot(-0.0625,0,'g.','MarkerSize',25)
    sink4 = plot(0.0625,0,'r.','MarkerSize',25)
    legend([source4,sink4],'Source','Sink')

    %set(gca,'FontSize',11)
    xlabel('x-as')
    ylabel('y-as')
    %title({'Source-Sink (met |Q_1| = |Q_2| en Q*l = c^{te}):','Stroomlijnen \psi & Snelheidsvectoren'},'FontSize',11)
    daspect([1 1 1])