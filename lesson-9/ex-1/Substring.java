class Substring implements Sequence{
    private Sequence text;
    private int begin;
    private int end;
    public Substring (Sequence t, int b, int e){
        text=t;
        begin=b;
        end=e;
    }
    @Override
    public String printedSeq(){
        return text.printedSeq().substring(begin,end);
    }
}
