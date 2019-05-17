close all;
%% Deel 1
clear;

% importeer data
vx = importdata('O5_D1_vectors_x.txt','\t');
vy = importdata('O5_D1_vectors_y.txt','\t');
S = importdata('O5_D1_stream.txt','\t');
P = importdata('O5_D1_potential.txt','\t');

% initialiseer grid
minX = -2.5; maxX = 2.5;
minY = -1; maxY = 1;
[nY,nX] = size(S);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

% plot: snelheidsvectoren & stroomlijnen
figure(1), hold on, box on;
streamslice(X,Y,vx,vy,5)

% labels
vortex = plot(0,0,'k.','MarkerSize',25)
legend([vortex],'Vortex')

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Vortex:','Stroomlijnen \psi & Snelheidsvectoren'})
daspect([1 1 1])
axis([-2.5 2.5 -1 1])

%% Deel 2
clear;

% importeer data
vx = importdata('O5_D2_vectors_x.txt','\t');
vy = importdata('O5_D2_vectors_y.txt','\t');
S = importdata('O5_D2_stream.txt','\t');
P = importdata('O5_D2_potential.txt','\t');

% initialiseer grid
minX = -2.5; maxX = 2.5;
minY = -1; maxY = 1;
[nY,nX] = size(S);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

% plot: snelheidsvectoren & stroomlijnen
figure(2), hold on, box on;
streamslice(X,Y,vx,vy,5)

% labels
vortex = plot(0,0,'k.','MarkerSize',25)
legend([vortex],'Vortex + Sink')

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Vortex en Sink:','Stroomlijnen \psi & Snelheidsvectoren'})
daspect([1 1 1])
axis([-2.5 2.5 -1 1])

%% Deel 3
clear;

% plots: Q*l = cte
figure(3);

subplot(4,1,1), hold on, box on;
    % data import
    vx = importdata('O5_D3_1_vectors_x.txt','\t');
    vy = importdata('O5_D3_1_vectors_y.txt','\t');
    %S = importdata('O5_D3_1_stream.txt','\t');
    %P = importdata('O5_D3_1_potential.txt','\t');
    
    % initialiseer grid
    minX = -2.5; maxX = 2.5;
    minY = -1; maxY = 1;
    [nY,nX] = size(vx);
    [X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));
    
    streamslice(X,Y,vx,vy,5)
    
    % labels
    vortex = plot(-2,0,'k.','MarkerSize',25)
    plot(2,0,'k.','MarkerSize',25)
    plot(0,0,'k.','MarkerSize',25)
    legend([vortex],'Vortex')

    %set(gca,'FontSize',11)
    xlabel('x-as')
    ylabel('y-as')
    title({'N Vortices op gelijke afstanden','Stroomlijnen \psi & Snelheidsvectoren'},'FontSize',11)
    daspect([1 1 1])
    axis([-2.5 2.5 -1 1])
    
subplot(4,1,2), hold on, box on;
    % data import
    vx = importdata('O5_D3_2_vectors_x.txt','\t');
    vy = importdata('O5_D3_2_vectors_y.txt','\t');
    %S = importdata('O5_D3_2_stream.txt','\t');
    %P = importdata('O5_D3_2_potential.txt','\t');
    
    % initialiseer grid
    minX = -2.5; maxX = 2.5;
    minY = -1; maxY = 1;
    [nY,nX] = size(vx);
    [X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));
    
    streamslice(X,Y,vx,vy,5)
    
    % labels
    vortex = plot(-2,0,'k.','MarkerSize',25)
    plot(2,0,'k.','MarkerSize',25)
    plot(-0.666,0,'k.','MarkerSize',25)
    plot(0.666,0,'k.','MarkerSize',25)
    legend([vortex],'Vortex')

    %set(gca,'FontSize',11)
    xlabel('x-as')
    ylabel('y-as')
    %title({'N Vortices op gelijke afstanden','Stroomlijnen \psi & Snelheidsvectoren'},'FontSize',11)
    daspect([1 1 1])
    axis([-2.5 2.5 -1 1])
    
subplot(4,1,3), hold on, box on;
    % data import
    vx = importdata('O5_D3_3_vectors_x.txt','\t');
    vy = importdata('O5_D3_3_vectors_y.txt','\t');
    %S = importdata('O5_D3_3_stream.txt','\t');
    %P = importdata('O5_D3_3_potential.txt','\t');
    
    % initialiseer grid
    minX = -2.5; maxX = 2.5;
    minY = -1; maxY = 1;
    [nY,nX] = size(vx);
    [X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));
    
    streamslice(X,Y,vx,vy,5)
    
    % labels
    vortex = plot(-2,0,'k.','MarkerSize',25)
    plot(2,0,'k.','MarkerSize',25)
    plot(0,0,'k.','MarkerSize',25)
    plot(1,0,'k.','MarkerSize',25)
    plot(-1,0,'k.','MarkerSize',25)
    legend([vortex],'Vortex')

    %set(gca,'FontSize',11)
    xlabel('x-as')
    ylabel('y-as')
    %title({'N Vortices op gelijke afstanden','Stroomlijnen \psi & Snelheidsvectoren'},'FontSize',11)
    daspect([1 1 1])
    axis([-2.5 2.5 -1 1])
    
subplot(4,1,4), hold on, box on;
    % data import
    vx = importdata('O5_D3_4_vectors_x.txt','\t');
    vy = importdata('O5_D3_4_vectors_y.txt','\t');
    %S = importdata('O5_D3_4_stream.txt','\t');
    %P = importdata('O5_D3_4_potential.txt','\t');
    
    % initialiseer grid
    minX = -2.5; maxX = 2.5;
    minY = -1; maxY = 1;
    [nY,nX] = size(vx);
    [X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));
    
    streamslice(X,Y,vx,vy,5)
    
    % labels
    vortex = plot(-2,0,'k.','MarkerSize',25)
    plot(2,0,'k.','MarkerSize',25)
    plot(-1.555,0,'k.','MarkerSize',25)
    plot(1.555,0,'k.','MarkerSize',25)
    plot(-1.111,0,'k.','MarkerSize',25)
    plot(1.111,0,'k.','MarkerSize',25)
    plot(0.666,0,'k.','MarkerSize',25)
    plot(-0.666,0,'k.','MarkerSize',25)
    plot(0.222,0,'k.','MarkerSize',25)
    plot(-0.222,0,'k.','MarkerSize',25)
    legend([vortex],'Vortex')

    %set(gca,'FontSize',11)
    xlabel('x-as')
    ylabel('y-as')
    %title({'N Vortices op gelijke afstanden','Stroomlijnen \psi & Snelheidsvectoren'},'FontSize',11)
    daspect([1 1 1])
    axis([-2.5 2.5 -1 1])
    
%% Deel 4
clear;

% importeer data
vx = importdata('O5_D4_vectors_x.txt','\t');
vy = importdata('O5_D4_vectors_y.txt','\t');
S = importdata('O5_D4_stream.txt','\t');
P = importdata('O5_D4_potential.txt','\t');

% initialiseer grid
minX = -2.5; maxX = 2.5;
minY = -1; maxY = 1;
[nY,nX] = size(S);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

% plot: snelheidsvectoren & stroomlijnen
figure(4), hold on, box on;
streamslice(X,Y,vx,vy,5)

% labels
vortex = plot(-2.5,0,'k.','MarkerSize',25)
plot([-2:0.5:2.5],0,'k.','MarkerSize',25)
legend([vortex],'Vortex')

set(gca,'FontSize',11)
xlabel('x-as')
ylabel('y-as')
title({'Vortexsheet:','Stroomlijnen \psi & Snelheidsvectoren'})
daspect([1 1 1])
axis([-2.5 2.5 -1 1])
    