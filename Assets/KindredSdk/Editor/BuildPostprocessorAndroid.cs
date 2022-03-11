using UnityEngine;
#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.Callbacks;
#endif

namespace KindredSDK.Editor
{
    public class BuildPostprocessorAndroid
    {
#if UNITY_EDITOR
        [PostProcessBuildAttribute(1)]
        public static void OnPostprocessBuild(BuildTarget target, string pathToBuiltProject)
        {
            if (target == BuildTarget.Android)
            {
                //Debug.Log("Postbuild buildPath: " + pathToBuiltProject);
            }
        }
#endif
    }
}