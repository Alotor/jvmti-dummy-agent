package alotor.jvmti;

class Main {
    public static void main(String[] args) {
        //System.loadLibrary("agent");

        NativeObject nativeObj = new NativeObject();
        nativeObj.helloFromC();

        System.out.println(">> OK");
    }
}
