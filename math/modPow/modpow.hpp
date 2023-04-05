long long modPow(long long a, long long b, long long p){
    if(b == 0) return 1;
    if(b == 1) return a % p;
    
    if(b % 2 == 1){
        return (a * modPow(a, b - 1, p)) % p;
    }else{
        long long t = modPow(a, b/2, p);
        return (t * t) % p;
    }
}
