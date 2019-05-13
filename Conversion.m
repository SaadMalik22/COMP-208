function S= Conversion(decimal)
S=mod(decimal,2);
decimal=floor(decimal/2);
if(decimal>0)
    S=Conversion(decimal)*10+S;
end
end 