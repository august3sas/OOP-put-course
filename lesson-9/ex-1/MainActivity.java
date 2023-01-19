public class MainActivity {
    public static void main(String[] args){
        Sequence seq= new Characters("LICZnik asYnCHRONICZny modulo 2137");
        String res=seq.printedSeq();
        System.out.println(res);
        
        Sequence seq1= new LowerCased(new Characters("licznik asynCHRONICZny modulo 2137"));
        String res1=seq1.printedSeq();
        System.out.println(res1);
        
        Sequence seq2 = new Concatenation(new Characters("zaprojektuj "),seq1);
        String res2=seq2.printedSeq();
        System.out.println(res2);
        
        Sequence seq3 = new Substring(seq2, 21,37);
        String res3=seq3.printedSeq();
        System.out.println(res3);
    }
}
