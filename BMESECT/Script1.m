cd 'D:\Code\Techjoin\BMESECT';
%% common commands
ver;  %see version
dir;  %file folder
cd '..\'  %jump up
path=which('Script1.m');  %show file path

%% vector and array
i,j,
%constructing symbolic variables and represent complex number
syms('a','b','c'); a=3; b=4; z=a+b*j, 
syms('A','theta'); theta=0.5236; A=1; z=A*exp(theta*j),
realmin, realmax, eps,

clear; clc;
a=10:3:30,
b=[1 2 3; 4 5 6],
b(:,1)=[],

c=magic(4),
cf=c(find(c>2)),

a=[1, 2*pi; sqrt(3), 4+5j],
b=a',
c=linspace(1,10,6),
d=logspace(1,10,6),

%% Matrix calculation
clear; clc;
% syms('k','A','B','C','D');
% k=6;
% A=[1 1 2; 3 5 8; 13 21 34],
% B=k.*A,
% k.*A==A.*k,
% C=[8 8 8; 5 5 5; 1 1 1],
% A.*C==C.*A,
% A*C==C*A,
% D=A./k,
% D=k./A,
% C=[1 2 8; 4 12 6; 69 8 9]
% D=inv(C),

% A=sym('[a11 a12; a21 a22]'); B=det(A),
% A=sym('[a11 a12 a13; a21 a22 a23; a31 a32 a33]'); B=det(A),
% B=inv(A),
% A*B,
% B=pinv(A),
% A*B,

% A=[1 3 -2; -1 2 4; 502 497 -490];
% A1=inv(A), 
% B1=A1*A, B1=A*A1,
% d=rank(A), %矩阵的秩
% [V,D]=eig(A), %矩阵的特征值和特征向量
% A*V==V*D, %D: 特征值矩阵，V:特征向量矩阵

% A=pascal(3),
% R=chol(A),
% R'*R==A, %Cholesky分解
% [L,U]=lu(A), %LU分解
% L*U==A,
% b=[1 2 3]',x=U\(L\b), %求解
% det(A)==det(L)*det(U), 

% A=[1 1 1;2 -1 -1; 2 -4 5];
% [Q,R,E]=qr(A), %E: 置换矩阵 Q: 正交矩阵 R: 上三角矩阵
% QTQ=Q.'*Q,
% B=Q*R, C=A*E,
% A*E==Q*R,

% A=[9 8;6 8];
% ATA=A'*A, [V,D]=eig(ATA), sigma=sqrt(D), %特征值的算术平方根
% [U,S,V]=svd(A), %奇异值分解
% UTU=U.'*U, VTV=V.'*V, %U和V为正交矩阵
% USV=U*S*V', %SVD分解

A=eye(3,3), %单位矩阵

%% Polynomial
clear; clc;
% p=[5 4 3 2 1]; roots(p), %指定系数求多项式根
% p1=poly([2,3,4]), %由多项式的根求系数
% y=polyval(p,8), %x=8时多项式的值

% p=[1 3 5]; q=[2 4 6];
% r=conv(p,q), s=deconv(r,p), %p,q卷积得到r; r,q反卷积得到p
% p1=polyder(p), %多项式求导数

x=[1 2 3 4 5];
y=[5.5 43.1 128 290.7 498.4];
p=polyfit(x,y,4), %4阶多项式拟合
X=[2 4 5;-1 0 3;7 1 5];
Y=polyval(p,X), %多项式求值
Z=polyvalm(p,X), %多项式求值--输入为矩阵

sym('y=1/(a*log(1-x-a)+c1)')
sym('f=2*log(t)*exp(t)*sqrt(pi)')
sym('z=sin(abs(x)+abs(y))/sqrt(cos(aabs(x+y)))')
sym('F=z/(z-exp(T*log(8)))')

%% Symbolic calculation
clear; clc;
syms('x','y');
collect(x^2*y+y*x-x^2-2*x) %Collect coefficients.合并同类项

syms x a b c d;
int(x)
int(x^2,a,b)
p=[a b; c d];
inver_p=inv(p)





