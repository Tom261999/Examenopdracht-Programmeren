%% Plot stream and vector functions

%% Set variables %%
minX=-2;
maxX=2;

minY=-1;
maxY=1;

%% Import data
% replace \t by space delimiter
S = importdata('stream.txt','\t'); 

P = importdata('pressure.txt','\t');

vx = importdata('vectors_X.txt','\t');
vy = importdata('vectors_Y.txt','\t');

%% Make grid
% here [Y,X] because output had loop over x then y 
[nY,nX] = size(S);
[X,Y] = meshgrid(linspace(minX,maxX,nX),linspace(minY,maxY,nY));

%% Draw results
figure
xlabel('x');
ylabel('y');
title('Source-sink pair')
set(gca,'FontSize',11);
hold on;

% Draw pressure coefficient
%contourf(X,Y,P,linspace(-2.0, 1.0, 20))
shading flat;
colorbar;

% Draw streamlines ( does not work together with contourf )
contour(X,Y,S,50) %last argument: #contour levels

% Draw vector field
quiver(X,Y,vx,vy,2); %last argument: scale factor arrows

% % % % % % Draw points and ellipse
% % % % % plot(-1.49,0,'r.','MarkerSize',20)
% % % % % plot(1.49,0,'r.','MarkerSize',20)
% % % % % plot(-1,0,'b.','MarkerSize',20)
% % % % % plot(1,0,'b.','MarkerSize',20)
% % % % % [elX,elY] = calculateEllipse(0,0,1.49,0.905,0);
% % % % % plot(elX,elY,'r-.','LineWidth',1.5)

