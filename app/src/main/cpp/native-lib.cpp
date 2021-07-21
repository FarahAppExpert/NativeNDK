#include
#include
#include
#include

extern "C" JNIEXPORT jstring  extern "C" jstring
Java_com_example_nativendk_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    __android_log_write(ANDROID_LOG_DEBUG, "API123", "Debug Log");

    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jstring  extern "C" jstring
Java_com_example_nativendk_MainActivity_sendYourName(
        JNIEnv* env,
        jobject, jstring firstName, jstring lastName) {
    char returnString[20];
    const char *fN = env->GetStringUTFChars(firstName, NULL);
    const char *lN = env->GetStringUTFChars(lastName, NULL);

    strcpy(returnString,fN); // copy string one into the result.
    strcat(returnString,lN); // append string two to the result.

    env->ReleaseStringUTFChars(firstName, fN);
    env->ReleaseStringUTFChars(lastName, lN);

    __android_log_write(ANDROID_LOG_DEBUG, "API123", returnString);

    return env->NewStringUTF(returnString);
}

extern "C"
JNIEXPORT jobjectArray  extern "C" jobjectArray
Java_com_example_nativendk_MainActivity_stringArrayFromJNI(JNIEnv *env, jobject jobj)
{

    char *days[]={"Java",
                  "Android",
                  "Django",
                  "SQL",
                  "Swift",
                  "Kotlin",
                  "Springs"};

    jstring str;
    jobjectArray day = 0;
    jsize len = 7;
    int i;

    day = env->NewObjectArray(len,env->FindClass("java/lang/String"),0);

    for(i=0;i<7;i++)
    {
        str = env->NewStringUTF(days[i]);
        env->SetObjectArrayElement(day,i,str);
    }


    return day;
}

extern "C"
JNIEXPORT jstringextern "C"
JNIEXPORT jobjectArray
extern "C"
JNIEXPORT JNICALL


