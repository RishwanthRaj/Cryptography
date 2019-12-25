import java.io.*;
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.*;
public class RSA_ALGO {
    public BigInteger p,q,n,phi,e,d;
    public RSA_ALGO()
    {
        Random ran=new SecureRandom();
        p=BigInteger.probablePrime(10, ran);
        q=BigInteger.probablePrime(10,ran);
        System.out.println("The primes are:");
        System.out.println(p);
        System.out.println(q);
        n=p.multiply(q); 
        System.out.println("The product of primes:");
        System.out.println(n);
        phi=(p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));
        e=BigInteger.probablePrime(10, ran);
        while(phi.gcd(e).compareTo(BigInteger.ONE)>0 &&e.compareTo(phi)<0)
        {
            e.add(BigInteger.ONE);
        }
        d=e.modInverse(phi);
    }
    public BigInteger encrypt(BigInteger p1)
    {
        return p1.modPow(e,n);
    }
    public BigInteger decrypt(BigInteger c1)
    {
        return c1.modPow(d,n);
    }
    public static void main(String ar[])throws IOException
    {
        RSA_ALGO r=new RSA_ALGO();
        System.out.println("1.encrypt    2.decrypt");
        Scanner sc=new Scanner(System.in);
        int c=sc.nextInt();
        if(c==1)
        {
            System.out.println("enter the value to be encrypted");
            int x=sc.nextInt();
            BigInteger r1=BigInteger.valueOf(x);
            System.out.println(r.encrypt(r1));
        }
        if(c==2)
        {
            System.out.println("enter the value to be decrypted");
            int x=sc.nextInt();
            BigInteger r1=BigInteger.valueOf(x);
            System.out.println(r.decrypt(r1));
        }
        
    }
}
