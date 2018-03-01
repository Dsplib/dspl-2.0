function [cdj, snj] = ellipj_func(k, u, iter)

    lnd = landen(k, iter);

    cdj = cos(u*pi/2);
    snj = sin(u*pi/2);

    for n = iter:-1:1
        cdj = (1+lnd(n))./(1./cdj + lnd(n)*cdj); 
        snj = (1+lnd(n))./(1./snj + lnd(n)*snj); 
    end

end
