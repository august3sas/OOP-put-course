class Concatenation implements Sequence{
    private Sequence text1;
    private Sequence text2;
    public Concatenation(Sequence t1,Sequence t2){
        text1=t1;
        text2=t2;
    }
    @Override
    public String printedSeq(){
        return text1.printedSeq()+text2.printedSeq();
    }
}
