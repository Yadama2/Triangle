
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

void runVertexAssembly(VertexArray const&vao, InVertex *inVertex, uint32_t v)
{
    getVertexID(vao, inVertex, v);
    setVertexAttributes(vao.vertexAttrib, inVertex);
}

void runPrimitiveAssembly(triangle_t *Triangle, VertexArray const&vao, Program const&prg, 
        uint32_t t)
{
    for (uint32_t v = 0; v < 3; v++)
    {
        InVertex inVertex;
        runVertexAssembly(vao, &inVertex, t+v);
        prg.vertexShader(Triangle->points[v], inVertex, prg.uniforms);
    }
}
