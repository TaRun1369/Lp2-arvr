using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class PlayerMovement : MonoBehaviour
{
    public Transform targetObject;
    public float rotationSpeed = 1500f;
    public float translationSpeed = 2f;
    public float scaleSpeed = 0.1f;

    void Update()
    {
        // Rotate the object when 'R' is pressed
        if (Input.GetKeyDown(KeyCode.R))
        {
            RotateObject();
        }

        // Scale the object when 'S' is pressed
        if (Input.GetKeyDown(KeyCode.S))
        {
            ScaleObject(1);
        }

        if (Input.GetKeyDown(KeyCode.W))
        {
            ScaleObject(-1);
        }

        // Translate the object using arrow keys
        TranslateObject();
    }

    void RotateObject()
    {
        // Rotate the object around its up axis
        float rotationAmount = rotationSpeed * Time.deltaTime;
        transform.Rotate(Vector3.up, rotationAmount);
    }

    void ScaleObject(float direction)
    {
        // Scale the object based on the scaleSpeed
        targetObject.localScale += new Vector3(scaleSpeed, scaleSpeed, scaleSpeed) * direction;
    }

    void TranslateObject()
    {
        // Translate the object using arrow keys
        float horizontal = Input.GetAxis("Horizontal") * translationSpeed * Time.deltaTime;
        float vertical = Input.GetAxis("Vertical") * translationSpeed * Time.deltaTime;

        targetObject.Translate(new Vector3(horizontal, vertical, 0));
    }
}
