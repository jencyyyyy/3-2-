%bits = input('prompt');
bits=[1 0 1 1 0 1 1 1];
bitrate = 1;
n = 1000; 
T = length(bits)/bitrate;
N = n*length(bits);
dt = T/N;
t = 0:dt:T;
x = zeros(1,length(t));

for i=1:length(bits)
  if bits(i)==1
    x((i-1)*n+1:i*n) = 1;
  end
end
plot(t, x, 'Linewidth', 3);
counter = 0;
result = zeros(1,length(bits));
for i = 1:length(t)
  if t(i)>counter
    counter = counter + 1;
    result(counter) = x(i);
  end
end
disp('NRZ Unipolar Decoding:');
disp(result);