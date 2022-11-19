clc,clear
m=input('m=');
n=input('n=');
if m<n 
    t=m;
    n=t;
    m=n;
end
t=mod(m,n);
while t~=0
    m=n;
    n=t;
    t=mod(m,n);
end
disp(n);

    