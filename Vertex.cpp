void setVertexAttributes(VertexAttrib const attrib[maxAttributes], InVertex *inVertex)
{
    for (uint32_t i = 0; i < maxAttributes; i++)
    {
        uint32_t ID = inVertex->gl_VertexID;
        uint64_t stride = (attrib[i].stride);
        uint64_t offset = (attrib[i].offset);
        uint8_t *buffer = (uint8_t *) attrib[i].bufferData;
        uint8_t *ptr;
        
        switch (attrib[i].type)
        {
            case AttributeType::EMPTY:
                continue;
            
            case AttributeType::FLOAT:
                ptr = buffer + offset + stride*ID;
                inVertex->attributes[i].v1 = *((float *)ptr);
                break;

            case AttributeType::VEC2:
                for (uint32_t j = 0; j < 2; j++)
                {
                    ptr = buffer + offset + stride*ID + j*4;
                    inVertex->attributes[i].v2[j] = *((float *)ptr);
                }
                break;

            case AttributeType::VEC3:
                for (uint32_t j = 0; j < 3; j++)
                {
                    ptr = buffer + offset + stride*ID + j*4;
                    inVertex->attributes[i].v3[j] = *((float *)ptr);
                }
                break;

            case AttributeType::VEC4:
                for (uint32_t j = 0; j < 4; j++)
                {
                    ptr = buffer + offset + stride*ID + j*4;
                    inVertex->attributes[i].v4[j] = *((float *)ptr);
                }
                break;
        }
    }
}
