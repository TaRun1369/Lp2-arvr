using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour
{
    public Material RedColor;
    public Material GreenColor;

    private Renderer renderer;
    private bool isRed = true;

    void Start()
    {
        renderer = GetComponent<Renderer>();
    }

    public void SwitchMaterial()
    {
        if (isRed)
        {
            renderer.material = GreenColor;
        }
        else
        {
            renderer.material = RedColor;
        }
        isRed = !isRed;
    }
}