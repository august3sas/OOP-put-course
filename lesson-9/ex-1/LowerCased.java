class LowerCased implements Sequence{
    private Sequence text;
    public LowerCased(Sequence t) {
        text = t;
    }
    @Override
    public String printedSeq() {
        return text.printedSeq().toLowerCase();
    }
}
