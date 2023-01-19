class Characters implements Sequence{
    private String text;
    public Characters(String t){
        text=t;
    }
    @Override
    public String printedSeq(){
        return text;
    }
}
