function [y] = landen(k, iter)
  y = zeros(iter,1);
  y(1) = k;
  for(n = 2:iter)
    y(n) = (y(n-1)/(1+sqrt(1-y(n-1)^2))).^2;
  end
end